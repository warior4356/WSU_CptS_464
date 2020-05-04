import rticonnextdds_connector as rti
from time import sleep
import asyncio
import random
import properties
import datetime


async def process_bus(route, vehicle, num_stops, time_between_stops):
    connector = rti.Connector("MyParticipantLibrary::Participant", "busNetwork.xml")
    position = connector.getOutput("Publisher::PositionWriter")
    accident = connector.getOutput("Publisher::AccidentWriter")

    loops = 0
    while loops < 3:
        current_stop = 1
        while current_stop <= num_stops:
            # Generate traffic
            traffic = random.choices([["Normal", 1.0], ["Light", .75], ["Heavy", 1.5]], [.65, .25, .1])
            await asyncio.sleep(time_between_stops * traffic[0][1])

            # Report position
            position.instance.set_string("timestamp", str(datetime.datetime.now()))
            position.instance.set_string("route", route)
            position.instance.set_string("vehicle", vehicle)
            position.instance.set_number("stopNumber", current_stop)
            position.instance.set_number("numStops", num_stops)
            position.instance.set_number("timeBetweenStops", time_between_stops)
            position.instance.set_string("trafficConditions", traffic[0][0])
            position.instance.set_number("fillInRatio", random.randint(0, 101))
            position.write()
            print("{0} is on route {1} at stop {2} at {3}".format(vehicle, route, current_stop,
                                                                  str(datetime.datetime.now())))

            # Check for accident
            if random.choices([True, False], [.1, .9])[0]:
                accident.instance.set_string("timestamp", str(datetime.datetime.now()))
                accident.instance.set_string("route", route)
                accident.instance.set_string("vehicle", vehicle)
                accident.instance.set_number("stopNumber", current_stop)
                accident.write()
                print("{0} reported an accident on route {1} before "
                      "stop {2} at {3}".format(vehicle, route, current_stop, str(datetime.datetime.now())))

            current_stop += 1

        loops += 1


if __name__ == "__main__":
    loop = asyncio.new_event_loop()

    tasks = [
        loop.create_task(process_bus(properties.route1, properties.route1Vehicle1,
                         properties.route1numStops, properties.route1TimeBetweenStops)),
        loop.create_task(process_bus(properties.route1, properties.route1Vehicle2,
                         properties.route1numStops, properties.route1TimeBetweenStops)),
        loop.create_task(process_bus(properties.route1, properties.route1Vehicle3,
                         properties.route1numStops, properties.route1TimeBetweenStops)),
        loop.create_task(process_bus(properties.route2, properties.route2Vehicle1,
                         properties.route2numStops, properties.route2TimeBetweenStops)),
        loop.create_task(process_bus(properties.route2, properties.route2Vehicle2,
                         properties.route2numStops, properties.route2TimeBetweenStops)),
        loop.create_task(process_bus(properties.route2, properties.route2Vehicle3,
                         properties.route2numStops, properties.route2TimeBetweenStops))
    ]

    loop.run_until_complete(asyncio.wait(tasks))

import rticonnextdds_connector as rti
import properties
import asyncio

async def ride_bus(route, name, start, destination):
    connector = rti.Connector("MyParticipantLibrary::Participant", "busNetwork.xml")
    position = connector.get_input("Subscriber::PositionReader")
    accident = connector.get_input("Subscriber::AccidentReader")
    bus = ""

    print(name + " is waiting for the bus at stop " + str(start) + " on route " + route)
    while len(bus) == 0:
        await asyncio.sleep(.01)
        position.take()
        for sample in position.samples:
                if sample.get_string("route") == route and sample.get_number("stopNumber") == start:
                    bus = sample.get_string("vehicle")
                    print(name + " is on " + bus)

    while not len(bus) == 0:
        await asyncio.sleep(.01)
        position.take()
        for sample in position.samples:
                if sample.get_string("vehicle") == bus and sample.get_number("stopNumber") == destination:
                    print(name + " got off " + bus + " at stop " + str(destination))
                    bus = ""
    print(name + " is at stop " + str(destination))

if __name__ == "__main__":
    loop = asyncio.new_event_loop()

    tasks = [
        loop.create_task(ride_bus(properties.route1, "Passenger 1", 2, 4)),
        loop.create_task(ride_bus(properties.route2, "Passenger 2", 3, 2))
    ]

    loop.run_until_complete(asyncio.wait(tasks))
    print("All passengers at their stops")

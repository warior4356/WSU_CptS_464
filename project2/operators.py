import rticonnextdds_connector as rti
import properties


def watch_buses():
    connector = rti.Connector("MyParticipantLibrary::Participant", "busNetwork.xml")
    position = connector.get_input("Subscriber::PositionReader")
    accident = connector.get_input("Subscriber::AccidentReader")

    while True:
        position.take()
        for sample in position.samples:
            print("Position: " + str(sample.get_dictionary()))

        accident.take()
        for sample in accident.samples:
            print("Accident: " + str(sample.get_dictionary()))

if __name__ == "__main__":
    watch_buses()
    print("All buses back at depot")

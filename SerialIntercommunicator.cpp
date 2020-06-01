#include "SerialIntercommunicator.h"

SerialIntercommunicator::SerialIntercommunicator()
{
    Serial.begin(250000);

    while (!Serial) {
        ; // wait for serial port to connect. Needed for native USB port only
    }

    Serial.println("Serial loaded");
    locationCommand.init();
}

SerialIntercommunicator::~SerialIntercommunicator() {}

void SerialIntercommunicator::run()
{

    if (read())
    {
        Serial.println("intercomm");

        switch (command[0]) {
        case 'v': servoCommand.init(0, dist.toInt())->execute(); break;
        case 'h': servoCommand.init(1, dist.toInt())->execute(); break;
        case 's': motorCommand.init(-1)->execute(); break;
        case 'f': motorCommand.init(1)->execute(); break;
        case 'b': motorCommand.init(3)->execute(); break;
        case 'l': motorCommand.init(0, dist.toInt())->execute(); break;
        case 'r': motorCommand.init(2, dist.toInt())->execute(); break;
        case 'o':
            locationCommand.execute();
            write(locationCommand.getResultString());
            break;
        case 't': break;  write(batteryController.run()); break;
        default:
            break;
        }
    }
}

boolean SerialIntercommunicator::read()
{
    if (Serial.available() > 0) {
        command = Serial.readString();
        dist = command.substring(1);
        return true;
    }
    return false;
}

void SerialIntercommunicator::write(const char * data)
{
    Serial.write(data);
}

void SerialIntercommunicator::write(const byte data)
{
    Serial.write(data);
}
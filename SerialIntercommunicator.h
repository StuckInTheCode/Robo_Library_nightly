#ifndef SerialIntercommunicator_H
#define SerialIntercommunicator_H

#include "Arduino.h"
#include "BatteryController.h"
#include "LocationAnalysisCommand.h"
#include "MotorMovementCommand.h"
#include "ServoMovementCommand.h"

class SerialIntercommunicator
{
 public: 
 
     SerialIntercommunicator()
     {
         Serial.begin(250000);

         while (!Serial) {
             ; // wait for serial port to connect. Needed for native USB port only
         }

         Serial.println("Serial loaded");
         locationCommand.init();
    }

     ~SerialIntercommunicator() {}

    void run()
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

    boolean  read()
    {
        if (Serial.available() > 0) {
            command = Serial.readString();
            dist = command.substring(1);
            return true;
        }
        return false;
    }

    void write(const char * data)
    {
        Serial.write(data);
    }

    void write(const byte data)
    {
        Serial.write(data);
    }

private:

    String command;
    String dist;

    LocationAnalysisCommand locationCommand;
    ServoMovementCommand servoCommand;
    MotorMovementCommand motorCommand;
    BatteryController batteryController;
};
#endif

#ifndef MovementController_H
#define MovementController_H
#include "Arduino.h"
#include "MotorMovementCommand.h"
#include "InfraSensor.h"
#include "UltraSoundSensor.h"
#include "PhotoSensitiveSensor.h"
#include "ServoMovementCommand.h"


class MovementController
{
public:
    int ikCenter = 14;
    int ikLeft = 15; 
    int ikRight = 16; 
    int ikBack = 17; 


    int trigPin = 10; 
    int echoPin = 9;

    int lightSensorPin = 18;

    MovementController()
    {
        USSensor.init(trigPin, echoPin);
        PSSensor.init(lightSensorPin);
        IRSensor.init(ikCenter, ikLeft, ikRight, ikBack);
        motorCommand.init(-1)->execute();
        servoCommand.init(0, 25)->execute();
        servoCommand.init(1, 25)->execute();
    }

    ~MovementController() {}

    void run()
    {
        if (MotorMovementCommand::isRunning())
        {
            int lightLevel = PSSensor.read();
            int forbiddenDirection = checkInfraSensors(true);

            //if (MotorMovementCommand::getCurrentDirection() == forbiddenDirection) //todo
            {
                switch (forbiddenDirection)
                {
                case 0:
                    motorCommand.init(3, 500)->execute();
                    motorCommand.init(2, 200)->execute();
                    motorCommand.init(1)->execute();
                    break;
                case 1:
                    motorCommand.init(3, 500)->execute();
                    motorCommand.init(2, 200)->execute();
                    motorCommand.init(1)->execute();
                    break;
                case 2:
                    motorCommand.init(3, 500)->execute();
                    motorCommand.init(0, 200)->execute();
                    motorCommand.init(1)->execute();
                    break;
                case 3:
                    motorCommand.init(1, 500)->execute();
                    motorCommand.init(0, 500)->execute();
                    motorCommand.init(3)->execute(); //time?
                }

                //boolean barrierInForward = checkUltraSoundSensor();
                //if (barrierInForward)
                //{
                //    motorCommand.init(0)->execute();
                //    motorCommand.init(2, 200)->execute(); //?
                //}
            }
        }
    }

    boolean checkUltraSoundSensor()
    {
        int distance = USSensor.read();

        if (distance < 30)
            return false;
        return true;
    }

    int checkInfraSensors(boolean allowForwardMovement)
    {
        int * irSensorsState = { IRSensor.read()};
        int returnDirection = -1;

        if (irSensorsState[1] == LOW) { //center
            motorCommand.init(0)->execute();
            returnDirection = 0;
        }
        else if (irSensorsState[1] == HIGH && irSensorsState[0] == LOW) { //center && left
            motorCommand.init(0)->execute();
            returnDirection = 1;
        }
        else if (irSensorsState[1] == HIGH && irSensorsState[2] == LOW) {//center && right
            motorCommand.init(0)->execute();
            returnDirection = 2;
        }
        else if (irSensorsState[4] == LOW) { //back
            motorCommand.init(0)->execute();
            returnDirection = 3;
        }

        return returnDirection;
    }

private:
    ServoMovementCommand servoCommand;
    MotorMovementCommand motorCommand;
    UltraSoundSensor USSensor;
    PhotoSensitiveSensor PSSensor;
    InfraSensor IRSensor;
};

#endif

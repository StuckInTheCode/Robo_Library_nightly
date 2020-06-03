#include "MovementController.h"

MovementController::MovementController()
{
    USSensor.init(trigPin, echoPin);
    PSSensor.init(lightSensorPin);
    IRSensor.init(ikCenter, ikLeft, ikRight, ikBack);
    Serial.println("Movement controller loaded");
    setInitialState();
}

void MovementController::setInitialState()
{
    motorCommand.init(-1)->execute();
    servoCommand.init(0, 25)->execute();
    servoCommand.init(1, 25)->execute();
}

MovementController::~MovementController() 
{
}

void MovementController::run()
{
    if (MotorMovementCommand::isRunning())
    {
        int lightLevel = PSSensor.read();

        //low lightning
        if (lightLevel < 512)
            MotorMovementCommand::setSpeed(100 * PSSensor.normalizeData());
        else
            MotorMovementCommand::setDefaultSpeed();

        boolean barrierInForward = checkUltraSoundSensor();
        int forbiddenDirection = checkInfraSensors(barrierInForward);

        //none 0 //break
        //center 1 // go back, turn right and forward
        //left 2 // go back, turn right and forward
        //center & left 3 // go back, turn right and forward
        //right 4 // go back, turn left and forward
        //center & right 5 // go back, left and forward
        //left & right 6 // go back and stop 
        //center & left & right 7 // go back and stop
        //back 8 // go forward

        switch (forbiddenDirection)
        {
        case 0:
            break;
        case 1: //forward
        case 2:
        case 3:
            if (MotorMovementCommand::getCurrentDirection() < 3)
            {
                motorCommand.init(3, 500)->execute();
                motorCommand.init(2, 200)->execute();
                motorCommand.init(1)->execute();
            }
            break;
        case 4://center && right
        case 5:
            if (MotorMovementCommand::getCurrentDirection() < 3)
            {
                motorCommand.init(3, 500)->execute();
                motorCommand.init(0, 200)->execute();
                motorCommand.init(1)->execute();
            }
            break;
        case 6://left & right
        case 7://& center
            if (MotorMovementCommand::getCurrentDirection() < 3)
            {
                motorCommand.init(3, 500)->execute();
                motorCommand.init(-1)->execute();
            }
            break;
        case 15:
            motorCommand.init(-1)->execute();
            break;
        default:
            if (MotorMovementCommand::getCurrentDirection() == 3)
            {
                motorCommand.init(1, 500)->execute();
                motorCommand.init(0, 500)->execute();
                motorCommand.init(3)->execute(); //time?
            }
            break;
        }
    }
}

boolean MovementController::checkUltraSoundSensor()
{
    int distance = USSensor.read();

    if (distance < 30)
        return false;
    return true;
}

int MovementController::checkInfraSensors(boolean allowForwardMovement)
{
    IRSensor.read();
    int * irSensorsState = IRSensor.getResultAsArray();
    int returnDirection = 0;
    int multiplier = 1;

    if (allowForwardMovement)
        irSensorsState[0] = HIGH;

    for (int index = 0; index < 4; index++)
    {
        returnDirection += irSensorsState[index] * multiplier;
        multiplier *= 2;
    }

    return returnDirection;
}
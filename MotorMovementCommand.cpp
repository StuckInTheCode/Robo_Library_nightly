#include "MotorMovementCommand.h"

boolean MotorMovementCommand::running = false;
int MotorMovementCommand::currentDirection = -1;
int MotorMovementCommand::speed = 100;
// = -1
MotorMovementCommand::MotorMovementCommand() : mTimeDelay(0)
{
    setSpeed(100);
    currentDirection = -1;
}
MotorMovementCommand::MotorMovementCommand(int direction, int timeDelay = 0) :  mTimeDelay(timeDelay) 
{
    setSpeed(100);
    currentDirection = direction;
}
//   

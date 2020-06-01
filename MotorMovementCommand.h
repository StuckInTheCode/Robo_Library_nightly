#ifndef MotorMovementCommand_h
#define MotorMovementCommand_h

#include "Arduino.h"
#include "InteractionCommand.h"
#include <AFMotor.h>

static AF_DCMotor motor1(1);
static AF_DCMotor motor2(2);
static AF_DCMotor motor3(3);
static AF_DCMotor motor4(4);

class MotorMovementCommand : public InteractionCommand
{
public:
    MotorMovementCommand();
    MotorMovementCommand(int direction, int timeDelay);
    ~MotorMovementCommand();

    static boolean isRunning();
    static int getCurrentDirection();
    static void setSpeed(int speed);
    static void setDefaultSpeed();
    void execute();

    MotorMovementCommand * init(int direction, int timeDelay = 0);

private:
    static int speed;
    static int currentDirection;
    static boolean running;
    int mTimeDelay;

    void stop();

    void goForward(int time);
    void goBack(long time);
    void turnRight(long time);
    void turnLeft(long time);

    void forward();
    void back();
    void left();
    void right();
};

#endif 

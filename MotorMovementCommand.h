#ifndef MotorMovementCommand_h
#define MotorMovementCommand_h

#include "Arduino.h"
#include "InteractionCommand.h"
#include <AFMotor.h>

static AF_DCMotor motor1(1);
static AF_DCMotor motor2(2);
static AF_DCMotor motor3(3);
static AF_DCMotor motor4(4);
static boolean running;
static int currentDirection = -1;

class MotorMovementCommand : public InteractionCommand
{
public:

    int speed = 100; //motors speed
    MotorMovementCommand(){};
    MotorMovementCommand(int direction, int timeDelay = 0): mDirection(direction), mTimeDelay(timeDelay) {};
    ~MotorMovementCommand() {}

    static boolean isRunning()
    {
        return running;
    }

    static int getCurrentDirection()
    {
        return currentDirection;
    }

    void execute()
    {
        currentDirection = mDirection;
        switch (mDirection)
        {
        case -1:
            stop();
            break;
        case 0:
            turnLeft(mTimeDelay);
            break;
        case 1:
            goForward(mTimeDelay);
            break;
        case 2:
            turnRight(mTimeDelay);
            break;
        case 3:
            goBack(mTimeDelay);
        }
    }

    MotorMovementCommand * init(int direction, int timeDelay = 0)
    {
        mDirection = direction;
        mTimeDelay = timeDelay;
        return this;
    }

private:
    int mDirection;
    int mTimeDelay;

    void stop() {
        running = false;
        motor1.run(RELEASE);
        motor2.run(RELEASE);
        motor3.run(RELEASE);
        motor4.run(RELEASE);  
        delay(1000);
    }

    void goForward(int time) {

        running = true;
        forward();
        if (time)
        {
            delay(time);
            stop();
        }
    }

    void goBack(long time) {

        running = true;
        back();
        if (time)
        {
            delay(time);
            stop();
        }
    }

    void turnRight(long time) {

        running = true;
        right();
        delay(time);
        stop();
    }

    void turnLeft(long time) {
        running = true;
        left();
        delay(time);
        stop();
    }

    void forward() {
        motor1.run(FORWARD);
        motor2.run(FORWARD); 
        motor3.run(FORWARD);
        motor4.run(FORWARD); 

        motor1.setSpeed(speed);
        motor2.setSpeed(speed);
        motor3.setSpeed(speed);
        motor4.setSpeed(speed); 
    }

    void back() {
        motor1.run(BACKWARD);
        motor2.run(BACKWARD); 
        motor3.run(BACKWARD); 
        motor4.run(BACKWARD); 

        motor1.setSpeed(speed);
        motor2.setSpeed(speed); 
        motor3.setSpeed(speed); 
        motor4.setSpeed(speed); 
    }

    void left()
    {
        motor1.run(BACKWARD);
        motor2.run(BACKWARD);
        motor3.run(FORWARD);
        motor4.run(FORWARD);

        motor1.setSpeed(speed); 
        motor2.setSpeed(speed); 
        motor3.setSpeed(speed); 
        motor4.setSpeed(speed); 
    }

    void right()
    {
        motor1.run(FORWARD);
        motor2.run(FORWARD);
        motor3.run(BACKWARD);
        motor4.run(BACKWARD);

        motor1.setSpeed(speed); 
        motor2.setSpeed(speed); 
        motor3.setSpeed(speed);
        motor4.setSpeed(speed);
    }
};

#endif 

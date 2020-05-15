#ifndef ServoMovementCommand_H
#define ServoMovementCommand_H

#include "Arduino.h"
#include "InteractionCommand.h"
#include <Adafruit_PWMServoDriver.h>

static Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
static boolean started = false;
#define SERVOMIN  150 
#define SERVOMAX  550 
#define SERVOPORT0 0 
#define SERVOPORT1 1

class ServoMovementCommand : public InteractionCommand
{
public:

    ServoMovementCommand(): mServoNum(0) , mDeg(90) {}
    ~ServoMovementCommand() {}

    void execute()
    {
        if (!started)
        {
            pwm.begin();
            pwm.setPWMFreq(60);
            started = true;
        }

        switch (mServoNum)
        {
        case 0:
            servoVertical(mDeg);
            break;
        case 1:
            servoHorizontal(mDeg);
            break;
        }
    }

    ServoMovementCommand * init(int servoNum, int deg)
    {
        mServoNum = servoNum;
        mDeg = deg;
        return this;
    }

private:

    int mDeg;
    int mServoNum;

    void servoVertical(int deg) {
        int pulselength = map(deg, 0, 180, SERVOMIN, SERVOMAX);
        pwm.setPWM(SERVOPORT1, 0, pulselength);
    }

    void servoHorizontal(int deg) {
        int pulselength = map(deg, 0, 180, SERVOMIN, SERVOMAX);
        pwm.setPWM(SERVOPORT0, 0, pulselength);

    }
};

#endif

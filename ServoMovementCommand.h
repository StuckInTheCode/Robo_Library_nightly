#ifndef ServoMovementCommand_H
#define ServoMovementCommand_H

#include "Arduino.h"
#include "InteractionCommand.h"
//#include "pch.h"
#include <Adafruit_PWMServoDriver.h>
static Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
#define SERVOMIN  150 
#define SERVOMAX  550 
#define SERVOPORT0 0 
#define SERVOPORT1 1

class ServoMovementCommand : public InteractionCommand
{
public:

    ServoMovementCommand() {};
//    ServoMovementCommand() 
//    {
//      if(!started)
//      {
//        //pwm.begin();
//        //pwm.setPWMFreq(60);
//        started = true;
//      }
//    };
//
//    ServoMovementCommand(int servoNum, int deg) : mServoNum(servoNum), mDeg(deg)
//    {
//      if(!started)
//      {
//      //pwm.begin();
//      //pwm.setPWMFreq(60);
//      started = true;
//    }
//    }
//
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

    boolean started = false;
    //static Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
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

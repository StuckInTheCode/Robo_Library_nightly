#include "ServoMovementCommand.h"

ServoMovementCommand::ServoMovementCommand() : mServoNum(0), mDeg(0) 
{
    Serial.println("ServoMovementCommand loaded");
}

ServoMovementCommand::~ServoMovementCommand() 
{
}

void ServoMovementCommand::execute()
{
    if (!started)
    {
        myservoHorizontal.attach(9);
        myservoHorizontal.write(0);
        //servoHorizontal(10);
        delay(1000);
        myservoVertical.attach(10);
        //servoVertical(10);
        myservoVertical.write(0);
        delay(1000);
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

ServoMovementCommand * ServoMovementCommand::init(int servoNum, int deg)
{
    mServoNum = servoNum;
    if (mServoNum == 0)
        prevDegVert = mDeg;
    else
        prevDegHor = mDeg;
    mDeg = deg;
    return this;
}

void ServoMovementCommand::servoVertical(int deg) {
    int dif = mDeg - prevDegVert;
    Serial.println(prevDegVert);
    if (dif > 5)
    {
        int i = 0;
        for (i = 2; prevDegVert + i < mDeg && i < dif; i += 2)
        {
            myservoVertical.write(prevDegVert + i);
            Serial.println(prevDegVert + i);
            delay(20);
        }
    }
    if (dif < -5)
    {
        int i = 0;
        for (i = -2; prevDegVert + i > mDeg && i > dif; i -= 2)
        {
            myservoVertical.write(prevDegVert + i);
            Serial.println(prevDegVert + i);
            delay(20);
        }
    }
    myservoVertical.write(deg);
    delay(40);
}

void ServoMovementCommand::servoHorizontal(int deg) {
    int dif = mDeg - prevDegHor;
    Serial.println(dif);
    if (dif > 5)
    {
        int i = 0;
        for (i = 2; prevDegHor + i < mDeg && i < dif; i += 2)
        {
            myservoHorizontal.write(prevDegHor + i);
            delay(50);
        }
    }
    if (dif < -5)
    {
        int i = 0;
        for (i = -2; prevDegHor + i > mDeg && i > dif; i -= 2)
        {
            myservoHorizontal.write(prevDegHor + i);
            delay(50);
        }
    }
    myservoHorizontal.write(deg);
    delay(100);
}
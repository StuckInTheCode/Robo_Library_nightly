#include "InfraSensor.h"

InfraSensor::InfraSensor() 
{
}

InfraSensor::InfraSensor(int centerPin, int leftPin, int rightPin, int backPin)
{
    mCenterPin = centerPin;
    mLeftPin = leftPin;
    mRightPin = rightPin;
    mBackPin = backPin;
}

InfraSensor::~InfraSensor()
{
}

void InfraSensor::init(int center, int left, int right, int back)
{
    mCenterPin = center;
    mLeftPin = left;
    mRightPin = right;
    mBackPin = back;
}

int InfraSensor::read()
{
    state = analogRead(mCenterPin) < 45 ? 1 : 0;
    state += 2 * (analogRead(mLeftPin) < 45 ? 1 : 0);
    state += 4 * (analogRead(mRightPin) < 45 ? 1 : 0);
    state += 8 * (analogRead(mBackPin) < 45 ? 1 : 0);

    return state;
}

int InfraSensor::getCenterPinState()
{
    return state & 0x0001;
}

int InfraSensor::getLeftPinState()
{
    return state & 0x0002;
}

int InfraSensor::getRightPinState()
{
    return state & 0x0004;
}

int InfraSensor::getBackPinState()
{
    return state & 0x0008;
}

int * InfraSensor::getResultAsArray()
{
    int * result = new int[4];

    result[0] = state & 0x0001;
    result[1] = state & 0x0002;
    result[2] = state & 0x0004;
    result[3] = state & 0x0008;

    return result;
}

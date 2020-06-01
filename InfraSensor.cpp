#include "InfraSensor.h"

InfraSensor::InfraSensor() 
{
}

InfraSensor::InfraSensor(int center, int left, int right, int back)
{
    ikCenter = center;
    ikLeft = left;
    ikRight = right;
    ikBack = back;
}

InfraSensor::~InfraSensor()
{
}

void InfraSensor::init(int center, int left, int right, int back)
{
    ikCenter = center;
    ikLeft = left;
    ikRight = right;
    ikBack = back;
}

int * InfraSensor::read()
{
    result[0] = digitalRead(ikCenter);
    result[1] = digitalRead(ikLeft);
    result[2] = digitalRead(ikRight);
    result[3] = digitalRead(ikBack);

    return result;
}

int * InfraSensor::getCurrentState()
{
    return result;
}
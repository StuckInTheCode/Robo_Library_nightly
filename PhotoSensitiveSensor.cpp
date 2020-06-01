#include "PhotoSensitiveSensor.h"

PhotoSensitiveSensor::~PhotoSensitiveSensor()
{
}

PhotoSensitiveSensor::PhotoSensitiveSensor() : lightLevel(0) 
{
}

void PhotoSensitiveSensor::init(int sensorPin)
{
    lightSensorPin = sensorPin;
    pinMode(sensorPin, INPUT);
}

int PhotoSensitiveSensor::read()
{
    lightLevel = analogRead(lightSensorPin);
    return lightLevel;
}

int PhotoSensitiveSensor::getCurrentState()
{
    return lightLevel;
}

float PhotoSensitiveSensor::normalizeData()
{
    float normal = (float)lightLevel / 512;
    return lightLevel;
}
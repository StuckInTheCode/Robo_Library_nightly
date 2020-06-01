#include "UltraSoundSensor.h"

UltraSoundSensor::UltraSoundSensor() : duration(0), distance(3000)
{

}

UltraSoundSensor::~UltraSoundSensor() 
{
}

void UltraSoundSensor::init(int trig, int echo)
{
    trigPin = trig;
    echoPin = echo;

    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

int UltraSoundSensor::read() 
{

    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH);
    // Calculating the distance
    distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
    return distance;
}

int UltraSoundSensor::getCurrentState()
{
    return distance;
}

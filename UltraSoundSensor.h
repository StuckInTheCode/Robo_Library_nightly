#ifndef UltraSoundSensor_H
#define UltraSoundSensor_H
#include "Arduino.h"

class UltraSoundSensor
{
public:
    UltraSoundSensor();
    ~UltraSoundSensor();

    void init(int trig, int echo);
    int read();
    int getCurrentState();

private:
    int trigPin;
    int echoPin;
    long duration;
    int distance;
};

#endif

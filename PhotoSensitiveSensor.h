#ifndef PhotoSensitiveSensor_H
#define PhotoSensitiveSensor_H
#include "Arduino.h"

class PhotoSensitiveSensor
{
public:
    PhotoSensitiveSensor();
    ~PhotoSensitiveSensor();

    int read();
    void init(int sensorPin);
    int getCurrentState();
    float normalizeData();

private:
    int lightLevel;
    int lightSensorPin;
};
#endif

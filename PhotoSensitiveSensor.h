#ifndef PhotoSensitiveSensor_H
#define PhotoSensitiveSensor_H
#include "Arduino.h"

class PhotoSensitiveSensor
{
  public:
  PhotoSensitiveSensor(): lightLevel(0) {}

  void init(int sensorPin) 
  {
      lightSensorPin = sensorPin;
      pinMode(sensorPin, INPUT);
  }
  ~PhotoSensitiveSensor();

  int read()
  {
      lightLevel = analogRead(lightSensorPin);
      return lightLevel;
  }

  int getCurrentState()
  {
      return lightLevel;
  }
private:
    int lightLevel;
    int lightSensorPin;
};
#endif

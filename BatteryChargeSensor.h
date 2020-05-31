#ifndef BatteryChargeSensor_H
#define BatteryChargeSensor_H

#include "Arduino.h"
#define R1 100000             
#define R2 51000

class BatteryChargeSensor
{
  public:
  BatteryChargeSensor() : voltage(0) {};
  BatteryChargeSensor(int voltPin): mVoltPint(voltPin), voltage(0) {};
  ~BatteryChargeSensor() {};

  void init(int voltPin)
  {
      mVoltPint = voltPin;
  }

  float read() {
      voltage = ((float)analogRead(mVoltPint)) / 1024 * ((R1 + R2) / R2);
      return voltage; 
  }

  float getCurrentState()
  {
      return voltage;
  }

private:
    int mVoltPint;
    float voltage;
};

#endif

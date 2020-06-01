#include "BatteryChargeSensor.h"

BatteryChargeMeasurer::BatteryChargeMeasurer() : voltage(0)
{
}

BatteryChargeMeasurer::BatteryChargeMeasurer(int voltPin) : mVoltPint(voltPin), voltage(0)
{
}

BatteryChargeMeasurer::~BatteryChargeMeasurer()
{
}

void BatteryChargeMeasurer::init(int voltPin)
{
    mVoltPint = voltPin;
}

float BatteryChargeMeasurer::read() {
    voltage = ((float)analogRead(mVoltPint)) / 1024 * ((R1 + R2) / R2);
    return voltage;
}

float BatteryChargeMeasurer::getCurrentState()
{
    return voltage;
}


﻿#ifndef LocationAnalysisCommand_H
#define LocationAnalysisCommand_H
#include "Arduino.h"
#include "InteractionCommand.h"
#include "UltraSoundSensor.h"
#include "InfraSensor.h"
#include "PhotoSensitiveSensor.h"

#define ikCenter 18
#define ikLeft 19
#define ikRight 17
#define ikBack 16 

#define trigPin 2
#define echoPin 15

#define lightSensorPin 18

class LocationAnalysisCommand : public InteractionCommand
{
public:
    LocationAnalysisCommand();
    ~LocationAnalysisCommand();

    void execute();
    const char * getResultString();
    LocationAnalysisCommand * init();

private:
    String mLocationState;
    UltraSoundSensor USSensor;
    PhotoSensitiveSensor PSSensor;
    InfraSensor IRSensor;
};

#endif

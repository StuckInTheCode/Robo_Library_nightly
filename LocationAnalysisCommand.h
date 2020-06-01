#ifndef LocationAnalysisCommand_H
#define LocationAnalysisCommand_H
#include "Arduino.h"
#include "InteractionCommand.h"
#include "UltraSoundSensor.h"
#include "InfraSensor.h"
#include "PhotoSensitiveSensor.h"
//class MovementController;

#define ikCenter 14
#define ikLeft 15
#define ikRight 16
#define ikBack 17

#define trigPin 10
#define echoPin 9

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
    String locationState;
    UltraSoundSensor USSensor;
    PhotoSensitiveSensor PSSensor;
    InfraSensor IRSensor;
};

#endif

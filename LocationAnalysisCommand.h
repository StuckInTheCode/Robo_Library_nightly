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

    LocationAnalysisCommand() 
    { 
        locationState = ""; 
    }

    //LocationAnalysisCommand(MovementController * controller) {}
    ~LocationAnalysisCommand() {}

    void execute()
    {
        int * irSensorsState = { IRSensor.read() };
        int distance = USSensor.read();
        int lightLevel = PSSensor.read();
        locationState = "";
        locationState += "i:";
        locationState += irSensorsState[0];
        locationState += ",";
        locationState += irSensorsState[1];
        locationState += ",";
        locationState += irSensorsState[2];
        locationState += ",";
        locationState += irSensorsState[3];
        locationState += "u:";
        locationState += distance;
        locationState += "l:";
        locationState += lightLevel;
        locationState += "\0";

        //create string;
    };

    const char * getResultString()
    {
        //char * result = new char[locationState];

        return locationState.c_str();
    }

    LocationAnalysisCommand * init()
    {
        USSensor.init(trigPin, echoPin);
        PSSensor.init(lightSensorPin);
        IRSensor.init(ikCenter, ikLeft, ikRight, ikBack);
    }

private:
    String locationState;

    UltraSoundSensor USSensor;
    PhotoSensitiveSensor PSSensor;
    InfraSensor IRSensor;
    //MovementController * mController;
};

#endif

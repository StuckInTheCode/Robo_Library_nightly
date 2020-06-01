#include "LocationAnalysisCommand.h"

LocationAnalysisCommand::LocationAnalysisCommand()
{
    locationState = "";
}

LocationAnalysisCommand::~LocationAnalysisCommand() 
{
}

void LocationAnalysisCommand::execute()
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
};

const char * LocationAnalysisCommand::getResultString()
{
    return locationState.c_str();
}

LocationAnalysisCommand * LocationAnalysisCommand::init()
{
    USSensor.init(trigPin, echoPin);
    PSSensor.init(lightSensorPin);
    IRSensor.init(ikCenter, ikLeft, ikRight, ikBack);
}

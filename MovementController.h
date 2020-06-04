#ifndef MovementController_H
#define MovementController_H
#include "Arduino.h"
#include "MotorMovementCommand.h"
#include "InfraSensor.h"
#include "UltraSoundSensor.h"
#include "PhotoSensitiveSensor.h"
#include "ServoMovementCommand.h"

#define ikCenter 18
#define ikLeft 19
#define ikRight 17
#define ikBack 16

#define trigPin 2 
#define echoPin 15

#define lightSensorPin 18

class MovementController
{
public:
    MovementController();
    ~MovementController();

    void setInitialState();
    void run();

private:
    boolean checkUltraSoundSensor();
    int checkInfraSensors(boolean allowForwardMovement);

    ServoMovementCommand servoCommand;
    MotorMovementCommand motorCommand;
    UltraSoundSensor USSensor;
    PhotoSensitiveSensor PSSensor;
    InfraSensor IRSensor;
};

#endif

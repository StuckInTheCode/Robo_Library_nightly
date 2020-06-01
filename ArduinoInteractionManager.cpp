#include "ArduinoInteractionManager.h"

ArduinoInteractionManager::ArduinoInteractionManager()
{
}


ArduinoInteractionManager::~ArduinoInteractionManager()
{
  
}

void ArduinoInteractionManager::begin()
{
    serialcomm = new SerialIntercommunicator();
    movement = new MovementController();
}

void ArduinoInteractionManager::handle()
{
    serialcomm->run();
    movement->run();
}
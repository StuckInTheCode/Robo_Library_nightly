#include "MovementController.h"
#include "SerialIntercommunicator.h"

class ArduinoInteractionManager
{
  public:
  ArduinoInteractionManager();
  ~ArduinoInteractionManager();

  void begin()
  {
      serialcomm = new SerialIntercommunicator();
      movement = new MovementController();
  }
  void handle()
  {
      serialcomm->run();
      movement->run();
  }

  private:
  MovementController * movement;
  SerialIntercommunicator * serialcomm;
};

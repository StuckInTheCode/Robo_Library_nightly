#include "MovementController.h"
#include "SerialIntercommunicator.h"

class ArduinoInteractionManager
{
public:
    ArduinoInteractionManager();
    ~ArduinoInteractionManager();

    void begin();
    void handle();

private:
    MovementController * movement;
    SerialIntercommunicator * serialcomm;
};

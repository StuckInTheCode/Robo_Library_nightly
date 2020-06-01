#ifndef InfraSensor_H
#define InfraSensor_H
#include "Arduino.h"

class InfraSensor
{
public:
    InfraSensor();
    InfraSensor(int center, int left, int right, int back);
    ~InfraSensor();

    void init(int center, int left, int right, int back);
    int * read();
    int * getCurrentState();

private:
    int result[4] = { LOW, LOW, LOW, LOW };
    int ikCenter;
    int ikLeft;
    int ikRight;
    int ikBack;
};

#endif

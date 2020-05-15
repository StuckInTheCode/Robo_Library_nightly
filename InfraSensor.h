#ifndef InfraSensor_H
#define InfraSensor_H
#include "Arduino.h"

class InfraSensor
{
public:
  
    InfraSensor()  {}
    InfraSensor(int center, int left, int right, int back)
    {
        ikCenter = center;
        ikLeft = left;
        ikRight = right;
        ikBack = back;
    }
    ~InfraSensor() {}

  void init(int center, int left, int right, int back)
  {
    ikCenter = center;
    ikLeft = left;
    ikRight = right;
    ikBack = back;
  }

  int * read()
  {
      result[0] = digitalRead(ikCenter);
      result[1] = digitalRead(ikLeft);
      result[2] = digitalRead(ikRight);
      result[3] = digitalRead(ikBack);

      return result;
  }

  int * getCurrentState()
  {
      return result;
  }

private:
    int result[4] = { LOW, LOW, LOW, LOW };
    int ikCenter;
    int ikLeft;
    int ikRight;
    int ikBack;
};

#endif

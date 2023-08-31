#include "Lyskryds.h"

Lyskryds light1(D0, D1, D2, D3, D4, D5);

void setup()
{
  light1.setup();
}

void loop()
{
  unsigned long currentTime = millis();

  light1.update(currentTime);
}
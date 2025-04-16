
#include "scheduler.h"
#include "softwareTimer.h"
#include "Arduino.h"



#define T_light 100 // update every second

void lightSwitch(int, int);
void analogueClockTask(void);
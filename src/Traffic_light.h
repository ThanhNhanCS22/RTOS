#include "scheduler.h"
#include "softwareTimer.h"
#include "Arduino.h"

#define T_light 1000 

void lightSwitch(int, int);
void trafficLightTask(void);
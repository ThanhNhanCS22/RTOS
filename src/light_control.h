#pragma  once 
#include "HTSensor.h" 

#define humidPin1 GPIO_NUM_10
#define humidPin2 GPIO_NUM_17
#define red 0 
#define yellow 1 
#define green 2 

void initializeLight(int, int) ; 
void lightStop(int, int) ; 
void lightRun(int, int, int ); 

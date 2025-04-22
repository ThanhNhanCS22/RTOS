#pragma once 

#include "HTSensor.h"
#include "Arduino.h"

// Pin definitions for humidifier control
#define humidPin1 GPIO_NUM_10
#define humidPin2 GPIO_NUM_17

// Threshold definitions (in percentage)
#define HUMID_THRESHOLD 45.0  // Humidity threshold to control humidifier

// Function declarations
void humidifierRun();

// External functions from light_control.h
extern boolean humidLightRun();
extern void humidLightStop();

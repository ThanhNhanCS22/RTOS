#pragma once 

#include "scheduler.h" 
#include "softwareTimer.h"
#include "Arduino.h"
#include "DHT20.h"

#define THRESHOLD_FREEZEING 0
#define THRESHOLD_LOW 10
#define THRESHOLD_NORMAL 30 
#define THRESHOLD_HOT 40 


#define HUMID_THRESHOLD 52  

extern DHT20 dht20;
extern float currTem ; 
extern float currHumid ; 

void HTSensor_Read() ; 
float  getSensorTemVal() ; 
float getSensorHumidVal() ; 
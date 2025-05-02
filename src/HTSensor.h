#pragma once 

#include "scheduler.h" 
#include "softwareTimer.h"
#include "Arduino.h"
#include "DHT20.h"

#define THRESHOLD_FREEZEING 0
#define THRESHOLD_LOW 10
#define THRESHOLD_NORMAL 30 
#define THRESHOLD_HIGH 40 


#define HUMID_THRESHOLD 65  

extern DHT20 dht20;

void HTSensor_Read() ; 
float  getSensorTemVal() ; 
float getSensorHumidVal() ; 
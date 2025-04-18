#include "scheduler.h"
#include "Blinky_led.h"
#include "traffic_light.h"
#include "softwareTimer.h"
#include "Arduino.h"


void setup(){
    SCH_Init();
   

    // these 2 are meant to trigger every cycle
    SCH_Add_Task(blinkyLedRun , 0, 1);
    SCH_Add_Task(trafficLightRun, 0, 1); // state machine
    SCH_Add_Task(timerRun, 0, 1); // software timer
}

void loop(){
    SCH_Dispatch_Tasks();

}
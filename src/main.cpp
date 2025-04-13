#include "scheduler.h"
#include "fsm_cx1.h"
#include "softwareTimer.h"
#include "Arduino.h"

void setup(){
    SCH_Init();
   

    // these 2 are meant to trigger every cycle
    SCH_Add_Task(fsm_run, 0, 1); // state machine
    SCH_Add_Task(timerRun, 0, 1); // software timer
}

void loop(){
    SCH_Dispatch_Tasks();
    delay(10) ; 
}
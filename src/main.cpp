#include "scheduler.h"
#include "fsm_cx1.h"
#include "softwareTimer.h"
#include "Arduino.h"

void setup(){
    SCH_Init();
    timerInit();

    SCH_Add_Task(fsm_run, 0, 100); 
}

void loop(){
    SCH_Update();
    SCH_Dispatch_Tasks();
    delay(1); // Prevent watchdog timer reset
}
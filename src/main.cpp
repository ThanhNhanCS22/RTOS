
// #include "Traffic_light.h"
#include "Analogue_clock.h" 

void setup(){
    SCH_Init();
    timerInit();

    // these 2 are meant to trigger every cycle
    SCH_Add_Task(fsm_run, 0, 1); // state machine
    SCH_Add_Task(timerRun, 0, 1); // software timer
}

void loop(){
    SCH_Update();
    SCH_Dispatch_Tasks();
    delay(10); // Prevent watchdog timer reset
}
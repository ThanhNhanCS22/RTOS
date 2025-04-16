
// #include "Traffic_light.h"
#include "Analogue_clock.h" 
#include "Blinky_led.h" 
void setup(){
    SCH_Init();
    timerInit();

    SCH_Add_Task(blinkyLedTask, 0, 1);
    SCH_Add_Task(analogueClockTask, 0, 1); 
    SCH_Add_Task(timerRun, 0, 1); 
}

void loop(){
    SCH_Update();
    SCH_Dispatch_Tasks();
    delay(10); 
}
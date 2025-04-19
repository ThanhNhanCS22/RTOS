
// #include "Traffic_light.h"
// #include "HTSensor.h"
#include "Blinky_led.h"
#include "Heater.h"
#include "cooler.h"
#include "humidifier.h"


void setup(){
   

 
    SCH_Init();
    
    SCH_Add_Task(timerRun, 0, 1); 
    SCH_Add_Task(blinkyLedRun, 0, 100);
    SCH_Add_Task(HTSensor_Read, 0 , 500) ; 
    SCH_Add_Task(humidifierRun, 0 , 1 ) ; 
    SCH_Add_Task(heaterRun, 0 , 100 ) ; 
    SCH_Add_Task(coolerRun, 0 , 1 ) ; 
    

}

void loop(){

    SCH_Dispatch_Tasks();
      
}
#include "Heater.h"



boolean isInitedHeater = false ; 

void heaterRun() {
    if(!isInitedHeater){
        initializeLight(heaterPin1, heaterPin2);   
        isInitedHeater = true ; 
        
        
    } 
    int temperature = getSensorTemVal() ; 

    if(temperature <= THRESHOLD_NORMAL  ) {
        lightRun(heaterPin1, heaterPin2,green );  
    }  
    if(temperature < THRESHOLD_LOW || temperature >THRESHOLD_NORMAL   ) {
        lightRun(heaterPin1, heaterPin2,yellow );  
        
    }
    if(temperature < THRESHOLD_FREEZEING || temperature > THRESHOLD_HOT ){
        lightRun(heaterPin1, heaterPin2,red );

    } 
}
#include "Heater.h"



boolean isInitedHeater = false ; 
void heaterRun() {
    if(!isInitedHeater){
        pinMode(GPIO_NUM_6, OUTPUT); 
        pinMode(GPIO_NUM_7 , OUTPUT) ; 
        isInitedHeater = true ; 

    } 

    if(currTem <= THRESHOLD_NORMAL  ) {
        digitalWrite(heaterPin1, HIGH ) ;
        digitalWrite(heaterPin2 , LOW ) ;
    }  
    if(currTem < THRESHOLD_LOW || currTem >THRESHOLD_NORMAL   ) {
        digitalWrite(heaterPin1, LOW ) ;
        digitalWrite(heaterPin2 , HIGH ) ;
    }
    if(currTem < THRESHOLD_FREEZEING || currTem > THRESHOLD_HOT ){
        digitalWrite(heaterPin1, HIGH ) ;
        digitalWrite(heaterPin2 , HIGH) ;
    } 


    
}
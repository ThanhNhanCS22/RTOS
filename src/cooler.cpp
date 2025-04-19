#include "cooler.h"

boolean  isInitedCooler  = false  ; 
boolean isCoolerTurnOn = false ; 

void coolerRun() {
    if(!isInitedCooler ){
        isInitedCooler = true ; 
        pinMode(GPIO_NUM_8, OUTPUT); 
        pinMode(GPIO_NUM_9 , OUTPUT) ; 
    } 
    switch(isCoolerTurnOn){
        case false : 
            if(currTem > THRESHOLD_NORMAL) {
                digitalWrite(coolerPin1, HIGH ) ; 
                digitalWrite(coolerPin2, LOW) ; 
                isCoolerTurnOn = true ; 
                setTimer(0,500);  
            }
            else{

                digitalWrite(coolerPin1, LOW ) ; 
                digitalWrite(coolerPin2, LOW) ; 
                
            }
            
            break; 
        case true : 
            if(!isTimerExpired(0)) break ; 
            isCoolerTurnOn = false ; 
    }


    
    
}

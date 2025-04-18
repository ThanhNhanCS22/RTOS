#include "Blinky_led.h"
#define ledPin GPIO_NUM_48  

int ledStatus = 0 ; 

void blinkyLedRun() {
    switch(ledStatus) {
        case 0 : 
            pinMode(ledPin, OUTPUT) ; 
            ledStatus = 1 ; 
            setTimer(1, 100);   
            break ; 
        
        case 1:   
            if(!isTimerExpired(1))  break ; 
            digitalWrite(ledPin, HIGH ) ;
            ledStatus = 2  ; 
            setTimer(1,100);  
            break ; 
        case 2: 
            if(!isTimerExpired(1))  break ; 
            digitalWrite(ledPin, LOW ) ;
            ledStatus =  1 ; 
            setTimer(1,100); 
            break ; 
            
    } 

} 
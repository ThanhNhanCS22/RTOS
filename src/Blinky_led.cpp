#include "Blinky_led.h"
#define ledPin GPIO_NUM_48 

int ledStatus = 0 ; 
void blinkyLedTask() {
    switch(ledStatus) {
        case 0 :
            pinMode(ledPin , OUTPUT ) ; 
            ledStatus  = 1 ; 
            digitalWrite(ledPin, HIGH ) ;
            break ; 
        case 1 : 
            if(!isTimerExpired(0 ) ) break ;  
            digitalWrite(ledPin, HIGH ) ;
            ledStatus = 2  ; 
            break ; 
        case 2 : 
            if(!isTimerExpired(0 ) ) break ;  
            digitalWrite(ledPin, LOW ) ;
            ledStatus = 1   ; 
            break ; 
          
    } 

} 
#include "Blinky_led.h"
#define ledPin GPIO_NUM_48  

int ledStatus = 0 ; 

void blinkyLedRun() {
    switch(ledStatus) {
        case 0 : 
            pinMode(ledPin  , OUTPUT ) ;
            ledStatus = 1 ;   
           
        case 1 :   
            digitalWrite(ledPin, LOW ) ;
            ledStatus = 2  ; 
            break ; 
        case 2 : 
            digitalWrite(ledPin, HIGH ) ;
            ledStatus = 1   ; 
            break ; 
          
    } 

} 
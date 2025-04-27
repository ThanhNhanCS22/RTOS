#include "Blinky_led.h"
#define ledPin GPIO_NUM_48  
#define init 0 
#define off 1  
#define on 2 

int ledStatus = 0 ; 

void blinkyLedRun() {
    switch(ledStatus) {
        case init  : 
            pinMode(ledPin  , OUTPUT ) ;
            ledStatus = on ;   
            break ; 
           
        case on  :   
            digitalWrite(ledPin, HIGH) ;
            ledStatus = off  ; 
            break ; 
        case off : 
            digitalWrite(ledPin, LOW ) ;
            ledStatus = on    ; 
            break ; 
          
    } 

} 
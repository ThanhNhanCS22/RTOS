
#include "light_control.h"

int humidLightStatus = 0 ; 

void humidLightStop( ){
    digitalWrite(humidPin1, LOW) ; 
    digitalWrite(humidPin2, LOW) ;
}

void intializeLight(int pin1, int pin2) {
    pinMode(pin1, OUTPUT) ; 
    pinMode(pin2, OUTPUT) ; 
}


 void lightRun(int pin1, int pin2, int color ){
       if(color == green ) {
            digitalWrite(pin1, HIGH)  ; 
            digitalWrite(pin2, LOW )  ; 
       }
       if (color == yellow ){
            digitalWrite(pin1, LOW)  ; 
            digitalWrite(pin2, HIGH)  ; 
       } 
       if(color == red ) {
            digitalWrite(pin1, HIGH ) ;
            digitalWrite(pin2, HIGH)  ; 
       }
}

void lightStop(int pin1, int pin2){

    digitalWrite(pin1, HIGH)  ; 
    digitalWrite(pin2, LOW )  ; 
} 
    


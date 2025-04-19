
#include "light_control.h"

int humidLightStatus = 0 ; 

void humidLightStop( ){
    digitalWrite(humidPin1, LOW) ; 
    digitalWrite(humidPin2, LOW) ;
}

boolean humidLightRun(){
    switch(humidLightStatus) {
        case 0  : 
            digitalWrite(humidPin1, HIGH) ; 
            digitalWrite(humidPin2, LOW) ; 
            humidLightStatus = 1 ; 
            setTimer(1,500 ) ; 
            break; 
        case 1 : 
            if(!isTimerExpired(1) ) break ; 
            digitalWrite(humidPin1, LOW) ; 
            digitalWrite(humidPin2, HIGH) ;
            humidLightStatus = 2 ;
            setTimer(1,300) ; 
            break ; 
        case 2 :
            if(!isTimerExpired(1) ) break ; 
            digitalWrite(humidPin1, HIGH) ; 
            digitalWrite(humidPin2, HIGH) ;
            humidLightStatus = 3 ;
            setTimer(1,200) ; 
            break ; 
        case 3 : 
            if(!isTimerExpired(1) ) break ; 
            humidLightStatus = 0 ; 
            return true ; 

    } 
    return false ; 
}

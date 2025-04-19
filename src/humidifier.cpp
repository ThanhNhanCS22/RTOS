#include "humidifier.h"
#include "light_control.h"

boolean isInitedHumidifier = false ; 
boolean isHumidifierTurnOn = false ; 

void humidifierRun() {
    if(!isInitedHumidifier){
        pinMode(humidPin1, OUTPUT) ;
        pinMode(humidPin2, OUTPUT) ;
        isInitedHumidifier = true ; 
    } 

    switch(isHumidifierTurnOn) {
        case false : 
            if(currHumid < HUMID_THRESHOLD) {
                humidLightRun() ;
                isHumidifierTurnOn = true ; 
            }
            else {
                humidLightStop() ; 
            }
            break ; 
        case true : 
            if(!humidLightRun()) break ; 
            isHumidifierTurnOn = false ; 
            

    }
    

}


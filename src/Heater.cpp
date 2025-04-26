#include "Heater.h"


#define heaterPin1 GPIO_NUM_6
#define heaterPin2 GPIO_NUM_7
#define init 0 
#define safe 1  
#define risk 2 
#define dangerous 3 
#define getTemperatureStage 4 

int heaterStatus = init ; 

int determineStage(float temperature){

    if(temperature <= THRESHOLD_NORMAL && temperature >= THRESHOLD_LOW   ) {
        return safe  ; 

    }  
    if((temperature < THRESHOLD_LOW && temperature >= THRESHOLD_FREEZEING) 
        || (temperature >THRESHOLD_NORMAL  && temperature <= THRESHOLD_HOT )  ) {
        return risk ;   
        
    }

    return dangerous; 
}

void heaterRun() {
    switch(heaterStatus ){
        case init : {
            initializeLight(heaterPin1,heaterPin2) ; 
            heaterStatus = getTemperatureStage ; 
            break ; 
        }
        
        case getTemperatureStage : {

            float temperature = getSensorTemVal() ; 
            heaterStatus = determineStage(temperature) ; 
        }

        case safe : {
            lightRun(heaterPin1 , heaterPin2, green) ;
            heaterStatus = getTemperatureStage ;
            break ; 
        }
        
        case risk : {

            lightRun(heaterPin1 , heaterPin2, yellow) ;
            heaterStatus = getTemperatureStage ;
            break ; 
        }
        
        case dangerous :{
            lightRun(heaterPin1 , heaterPin2, red) ;
            heaterStatus = getTemperatureStage ;
            break ; 
        }

    }
}
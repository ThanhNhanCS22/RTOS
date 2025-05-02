#include "Heater.h"


#define heaterPin1 GPIO_NUM_6
#define heaterPin2 GPIO_NUM_7
#define init 0 
#define safe 1  
#define risk 2 
#define dangerous 3 
#define heaterRunningStage  4 
#define waitingStage 5 

int heaterStatus = init ; 

int determineStage(float temperature){

    int temperatureStatus  ; 

    if(temperature <= THRESHOLD_NORMAL    ) 
        temperatureStatus = safe   ; 

    
    if(temperature < THRESHOLD_LOW ||
        temperature >THRESHOLD_NORMAL   ) 
        temperatureStatus = risk ;   
        
    

    if(temperature <= THRESHOLD_FREEZEING  || 
        temperature >= THRESHOLD_HIGH  ) 
        temperatureStatus = dangerous ; 
    
    
    return temperatureStatus ; 

}

void heaterRun() {
    switch(heaterStatus ){
        case init : {
            initializeLight(heaterPin1,heaterPin2) ; 
            heaterStatus = waitingStage ; 
            setTimer(3 ,399 ) ; 
            break ; 
        }
        case waitingStage : {
            if(!isTimerExpired(3 )) break ; 
            heaterStatus = heaterRunningStage ; 
            break ; 
        }
        
        case heaterRunningStage : {

            float temperature = getSensorTemVal() ; 
            int currTemperatureStage = determineStage(temperature) ; 


            if(currTemperatureStage == safe){
                lightRun(heaterPin1 , heaterPin2, green) ;
            } 
            if (currTemperatureStage == risk ){
                lightRun(heaterPin1 , heaterPin2, yellow) ;
            } 
            if(currTemperatureStage == dangerous ){
                lightRun(heaterPin1 , heaterPin2, red) ;
            } 
             
        }

    }
}
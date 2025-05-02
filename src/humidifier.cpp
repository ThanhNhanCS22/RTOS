#include "humidifier.h"
 

#define humidPin1 GPIO_NUM_10
#define humidPin2 GPIO_NUM_17
#define init 0 
#define checkingStage 1 
#define greenStage 2 
#define yellowStage 3 
#define redStage 4 
#define waitingStage 5 

int humidifierStatus  = init ; 

void humidifierRun() {

    switch (humidifierStatus) {

        case init : 
            initializeLight(humidPin1,humidPin2 ); 
            humidifierStatus = waitingStage;
            setTimer(1,499) ; 
            break;
        

        case waitingStage : {
            if(!isTimerExpired(1) ) break ; 
            humidifierStatus =  checkingStage ;
            break ; 
        }
        case checkingStage : {
            

            float currHumidity = getSensorHumidVal(); 
            
            if (currHumidity < HUMID_THRESHOLD) {
             
                lightRun(humidPin1, humidPin2, green);   
                humidifierStatus =  greenStage ; 
                setTimer(1, 500 ) ;  
            }
            break ; 
        }
            
        case greenStage  : {
            if(!isTimerExpired(1) ) break ;  
            lightRun(humidPin1, humidPin2, yellow) ; 
            setTimer(1, 300) ;
            humidifierStatus = yellowStage ;
            break ;  
        }
            
        case yellowStage : {
            if(!isTimerExpired(1) ) break ;  
            lightRun(humidPin1, humidPin2, red) ; 
            setTimer(1, 200) ;
            humidifierStatus = redStage ;
            break ;
        }

        case redStage : {
            if(!isTimerExpired(1) ) break ;  
            lightStop(humidPin1, humidPin2) ; 
            humidifierStatus = checkingStage ;  
            break ; 
        }
        
    }
}


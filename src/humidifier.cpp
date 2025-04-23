#include "humidifier.h"
#include "light_control.h"

#define humidPin1 GPIO_NUM_10
#define humidPin2 GPIO_NUM_17
#define Init 0 
#define checkingStage 1 
#define greenStage 2 
#define yellowStage 3 
#define redStage 4 

int humidifierStatus  = Init ; 

void humidifierRun() {

    switch (humidifierStatus) {

        case Init : 
            initializeLight(humidPin1,humidPin2 ); 
            humidifierStatus = 1;
            setTimer(1,500); 
            break;
        

       
        case checkingStage : {
            if(!isTimerExpired(1) ) break ; 

            float humidity = getSensorHumidVal(); 
            
            if (humidity < HUMID_THRESHOLD) {
             
                lightRun(humidPin1, humidPin2, green);   
                humidifierStatus =  2 ; 
                setTimer(1, 500 ) ;  
            }
            break ; 
        }
            
        case greenStage  : {
            if(!isTimerExpired(1) ) break ;  
            lightRun(humidPin1, humidPin2, yellow) ; 
            setTimer(1, 300) ;
            humidifierStatus = 3 ;
            break ;  
        }
            
        case yellowStage : {
            if(!isTimerExpired(1) ) break ;  
            lightRun(humidPin1, humidPin2, red) ; 
            setTimer(1, 200) ;
            humidifierStatus = 4 ;
            break ;
        }

        case redStage : {
            if(!isTimerExpired(1) ) break ;  
            lightStop(humidPin1, humidPin2) ; 
            humidifierStatus = 1 ;  
        }
        
    }
}


#include "cooler.h"


#define coolerPin1 GPIO_NUM_8
#define coolerPin2 GPIO_NUM_9
#define init 0 
#define checkingStage 1  
#define waitingStage 2 
#define coolerRunningStage 3 

int coolerStatus = init; 

void coolerRun() {
    switch (coolerStatus) { 
        case init : {
            initializeLight(coolerPin1, coolerPin2) ;  
            coolerStatus = waitingStage ; 
            setTimer(0,499  );  
            break;
        }

        case waitingStage : {
            if (!isTimerExpired(0) ) break ; 
            coolerStatus = checkingStage  ;
            break ;  
        }

         
        case checkingStage : { 

            float currTemperature = getSensorTemVal(); 

            if(currTemperature > THRESHOLD_NORMAL)  {
                coolerStatus = coolerRunningStage;   
                lightRun(coolerPin1, coolerPin2, green) ;
                setTimer(0,500 ) ; 
                   
            }
            else lightStop(coolerPin1, coolerPin2) ;  
        
            break ; 
            
        }
        
        
        case coolerRunningStage : {
            if(!isTimerExpired(0)) break; 
            coolerStatus = checkingStage; 
            break; 
        }
    }
}

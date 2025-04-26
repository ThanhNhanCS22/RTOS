#include "cooler.h"
#include "light_control.h"

#define coolerPin1 GPIO_NUM_8
#define coolerPin2 GPIO_NUM_9
#define Init 0 
#define checkingStage 1  
#define turnCoolerOffStage 2 
#define turnCoolerOnStage 3  
#define runningStage 4 

int coolerStatus = Init; 

void coolerRun() {
    switch (coolerStatus) { 
        case Init : {
            initializeLight(coolerPin1, coolerPin2) ;  
            coolerStatus = checkingStage; 
            setTimer(0,500);  
            break;
        }
         
        case checkingStage : {
            if(!isTimerExpired(0)) break;  

            float temperature = getSensorTemVal(); 

            if(temperature > THRESHOLD_NORMAL)  coolerStatus = turnCoolerOnStage;   
            
            else coolerStatus = turnCoolerOffStage ; 
            
        }
        case turnCoolerOffStage : {
            lightStop(coolerPin1, coolerPin2 ); 
            coolerStatus = checkingStage ; 
            break ; 
        }
        
        case turnCoolerOnStage : {
            lightRun(coolerPin1, coolerPin2, green) ; 
            coolerStatus =  runningStage ; 
            setTimer(0,500) ;  
            break ;  
        }
        case runningStage : {
            if(!isTimerExpired(0)) break; 
            coolerStatus = checkingStage; 
            break; 
        }
    }
}

#include "cooler.h"


int coolerStatus  ; 

void coolerRun() {
    switch (coolerStatus) { 
        case Init : 
            initializeLight(coolerPin1, coolerPin2) ;  
            coolerStatus = 1 ; 
            setTimer(0,500) ;  
            break ; 
         
        
        case 1 : 
            if(!isTimerExpired(0) ) break ;  

            float temperature  = getSensorTemVal() ; 

            if(temperature > THRESHOLD_NORMAL) {
                lightRun(coolerPin1, coolerPin2, green) ;
                coolerStatus = 2 ;   
                setTimer(0,500);  
            }

            else lightStop(coolerPin1, coolerPin2 ) ;     
            break; 

        case 2 : 
            if(!isTimerExpired(0)) break ; 
            coolerStatus = 1 ; 
            break ; 
    }

    
    
}

#include "cooler.h"
#include "light_control.h"

#define coolerPin1 GPIO_NUM_8
#define coolerPin2 GPIO_NUM_9
#define Init 0 

int coolerStatus = Init; 

void coolerRun() {
    switch (coolerStatus) { 
        case Init : {
            pinMode(coolerPin1, OUTPUT);
            pinMode(coolerPin2, OUTPUT);  
            coolerStatus = 1; 
            setTimer(0,500);  
            break;
        }
         
        case 1 : {
            if(!isTimerExpired(0)) break;  

            float temperature = getSensorTemVal(); 

            if(temperature > THRESHOLD_NORMAL) {
                digitalWrite(coolerPin1, HIGH);
                digitalWrite(coolerPin2, LOW);
                coolerStatus = 2;   
                setTimer(0,500);  
            }
            else {
                digitalWrite(coolerPin1, LOW);
                digitalWrite(coolerPin2, LOW);
            }
            break;
        }

        case 2 : {
            if(!isTimerExpired(0)) break; 
            coolerStatus = 1; 
            break; 
        }
    }
}

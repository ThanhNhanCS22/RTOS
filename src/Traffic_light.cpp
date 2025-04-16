
#include "Traffic_light.h"


#define D3 6
#define D4 7
#define D5 8
#define D6 9

#define L_RED 1
#define L_YELLOW 2
#define L_GREEN 3

int lightStatus = 0;

void lightSwitch(int Lcode, int colour){

    switch(colour){
        case L_RED:
            digitalWrite(Lcode, HIGH);
            digitalWrite(Lcode + 1, HIGH);
            break;
        case L_YELLOW:
            digitalWrite(Lcode, LOW);
            digitalWrite(Lcode + 1, HIGH);
            break;
        case L_GREEN:
            digitalWrite(Lcode, HIGH);
            digitalWrite(Lcode + 1, LOW);
            break;
        default:
            digitalWrite(Lcode, LOW);
            digitalWrite(Lcode + 1, LOW);
    }
}

void trafficLightTask(){
    switch(lightStatus){
        case 0:
            lightStatus = 1;
      
            pinMode(D3, OUTPUT); 
            pinMode(D4, OUTPUT); 
            pinMode(D5, OUTPUT); 
            pinMode(D6, OUTPUT); 
            lightSwitch(D3, L_RED); 
            lightSwitch(D5, L_GREEN);
            setTimer(0,300);  
            break;
        case 1: 
            if( !(isTimerExpired(0)) ) break ; 
            lightSwitch(D3, L_RED); 
            lightSwitch(D5, L_YELLOW);
            setTimer(0,200);  
            lightStatus = 2 ; 
            break;
        case 2:
            if( !(isTimerExpired(0)) ) break ; 
            lightSwitch(D3, L_GREEN); 
            lightSwitch(D5, L_RED);
            setTimer(0,300);  
            lightStatus = 3 ; 
            break;
        case 3:
            if( !(isTimerExpired(0)) ) break ; 
            lightSwitch(D3, L_YELLOW); 
            lightSwitch(D5, L_RED);
            setTimer(0,200);  
            lightStatus = 4 ; 
            break;
        case 4:
            if( !(isTimerExpired(0)) ) break ; 
            lightSwitch(D3, L_RED); 
            lightSwitch(D5, L_GREEN);
            setTimer(0,300);  
            lightStatus = 1 ; 
            break;
        default: 
            lightStatus = 0;
            break;
    }
}
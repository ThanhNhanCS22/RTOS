

#include "Analogue_clock.h"
#include <cstdlib>  

// 4 light devices, each to 2 pins
#define D3 6
#define D4 7
#define D5 8
#define D6 9
#define D7 10
#define D8 17
#define D9 18
#define D10 21

#define L_RED 0
#define L_YELLOW 1
#define L_GREEN 2

void lightSwitch(int pin1, int pin2,  int colour){
    switch(colour){
        case L_RED:
            digitalWrite(pin1 , HIGH);
            digitalWrite (pin2 , HIGH);
            break;

        case L_YELLOW:
            digitalWrite(pin1, LOW);
            digitalWrite(pin2 , HIGH);
            break;

        case L_GREEN:
            digitalWrite(pin1, HIGH);
            digitalWrite(pin2, LOW);
            break;
        default : 
            digitalWrite(pin1, LOW);
            digitalWrite(pin2, LOW);
      
    }
}

void clockSwitch(int position, int colour  ){
 
    switch(position) {
      
        case 0 : 
            lightSwitch(D3, D4, colour ) ;
            break ; 
        case 1 : 
            lightSwitch(D5 , D6 , colour ) ;
            break ; 
        case 2 : 
            lightSwitch(D7 , D8 , colour ) ;
            break ; 
        case 3 : 
            lightSwitch(D9 , D10 , colour ) ;
            break ;


    } 
    
   
}

int timeSeconds = 0; // 0 to 43200 (12 hours)
int Hhd = 0, Mhd = 0, Shd = 0; // hands: hours, minutes, seconds
int clock_status = 0; 

void analogueClockTask(){
    switch(clock_status){
        case 0:
            clock_status = 1;
            setTimer(0, 100);
            // initialise the lights
            pinMode(D3, OUTPUT); pinMode(D4, OUTPUT); 
            pinMode(D5, OUTPUT); pinMode(D6, OUTPUT); 
            pinMode(D7, OUTPUT); pinMode(D8, OUTPUT);
            pinMode(D9, OUTPUT); pinMode(D10, OUTPUT);
            
          
            clockSwitch( 0, 0 ); 
            
           
            break;

        case 1:
            
            if (!isTimerExpired(0 ) ) break ;
          
            timeSeconds++ ; 
            Hhd = (timeSeconds  / 3600) % 12    ; 
            Mhd =  (timeSeconds  / 60)  %60    ; 
            Shd = timeSeconds %60 ;

            clockSwitch( ((Hhd - 1 + 12) %12)/3 ,3  ); 
            clockSwitch(Hhd/3  , Hhd%3 ); 

       
            if(  ((Mhd - 1 + 60 ) %60)/15 != Hhd/3 ) ; 
                clockSwitch(  ((Mhd - 1 + 60 ) %60)/ 15,   3   ) ; 
            clockSwitch( Mhd/15,   (Mhd/5)%3 ) ;


            if( ((Shd - 1+ 60 )%60)/15 != Mhd/15 &&   ((Shd - 1+ 60 )%60)/15 !=  Hhd/3) ; 
                    clockSwitch(((Shd - 1+ 60 )%60)/15, 3 ) ; 
            clockSwitch(  Shd/15,    (Shd/5)%3); 


            setTimer(0 ,100) ;  

      
    }
}
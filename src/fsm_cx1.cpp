#include "softwareTimer.h"
#include "fsm_cx1.h"
#include "Arduino.h"

#define LED_ON 1
#define LED_OFF 0
#define INIT 2

#define LED_PIN 48

int fsm_status = INIT;

void led_on(){
    digitalWrite(LED_PIN, HIGH);
}

void led_off(){
    digitalWrite(LED_PIN, LOW);
}

void fsm_run(){
    switch(fsm_status){
        case INIT:
            fsm_status = LED_ON;
            setTimer(0, T_on);
            break;
        case LED_ON:
            led_on();
            if(isTimerExpired(0) == 1){
                fsm_status = LED_OFF;
                setTimer(0, T_off);
            }
            break;
        case LED_OFF:
            led_off();
            if(isTimerExpired(0) == 1){
                fsm_status = LED_ON;
                setTimer(0, T_on);
            }
            break;
        default: 
            fsm_status = INIT;
            break;
    }
}
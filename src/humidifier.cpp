#include "humidifier.h"
#include "light_control.h"

int humidifierStatus  = Init ; 


void humidifierRun() {

    switch (humidifierStatus) {

        case Init : 
            intializeLight(humidPin1,humidPin2 ); 
            humidifierStatus = 1;
            setTimer(1,500); 
            break;
        

       
        case 1 : 
            int humidity = getSensorHumidVal(); 
            
            if (humidity < HUMID_THRESHOLD) {
                // Humidity is below threshold, turn on humidifier
                digitalWrite(humidPin1, HIGH);
                digitalWrite(humidPin2, LOW);
                
                // Start indicator light
                if (humidLightRun()) {
                    isHumidifierTurnOn = true;
                    Serial.println("Humidifier turned ON - Current humidity: " + String(currHumid) + "%");
                } else {
                    Serial.println("Warning: Failed to start humidity indicator light");
                }
            }
        
        else {
            // Humidifier is currently on, check if it can be turned off
            if (currHumid >= HUMID_THRESHOLD) {
                // Humidity is at or above threshold, turn off humidifier
                digitalWrite(humidPin1, LOW);
                digitalWrite(humidPin2, LOW);
                
                // Stop indicator light
                humidLightStop();
                isHumidifierTurnOn = false;
                Serial.println("Humidifier turned OFF - Current humidity: " + String(currHumid) + "%");
            } else {
                // Still need humidifier, ensure light is running
                humidLightRun();
            }
        }
    }
}


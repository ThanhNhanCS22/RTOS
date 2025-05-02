#include "HTSensor.h" 

#define  init 0 
#define sensorRunningStage 1 


DHT20 dht20 ;
int sensorStatus = init ; 

void HTSensor_Read() {
        switch(sensorStatus) {
            case(init) : {
                Serial.begin(115200); 
                Wire.begin(GPIO_NUM_11, GPIO_NUM_12); 
                
                dht20.begin();
                sensorStatus = sensorRunningStage ; 
                break; 
                

            } 

            case(sensorRunningStage) :  { 
                dht20.read();

                // Reading temperature in Celsius
                float currTem = getSensorTemVal() ; 
                // Reading humidity
                float currHumid = getSensorHumidVal( ) ; 
            
                // Check if any reads failed and exit early
                if (isnan(currTem) || isnan(currHumid)) {
                    Serial.println("Failed to read from DHT sensor!");
                    return;
                }
            
                // Print the results 
                Serial.print("Humidity: ");
                Serial.print(currHumid);
                Serial.print("% Temperature: ");
                Serial.print(currTem);
                Serial.println("°C");

                break ; 
            }
        
        }
}

float getSensorTemVal() { 
    return dht20.getTemperature();
}

float getSensorHumidVal() {
    return dht20.getHumidity(); 
}
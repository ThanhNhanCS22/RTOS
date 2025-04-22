#include "HTSensor.h" 

 

boolean isInitedSensor = false ; 
DHT20 dht20 ;
float currTem ; 
float currHumid; 

void HTSensor_Read() {
            if(!isInitedSensor ){
                Wire.begin(GPIO_NUM_11, GPIO_NUM_12); 
                Serial.begin(115200); 
                dht20.begin();
                isInitedSensor = true ; 
            } 
    
            dht20.read();

            // Reading temperature in Celsius
            currTem = getSensorTemVal() ; 
            // Reading humidity
            currHumid = getSensorHumidVal( ) ; 
        
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

        

}

float getSensorTemVal() { 
    return dht20.getTemperature();
}

float getSensorHumidVal() {
    return dht20.getHumidity(); 
}
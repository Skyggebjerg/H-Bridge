/*
*******************************************************************************
* Product: Hbridge Unit
* getMotorCurrent() only support in v1.1 function
*******************************************************************************
*/

#include <Arduino.h>
#include "M5Atom.h"
#include "UNIT_HBRIDGE.h"

UNIT_HBRIDGE driver;

void setup() {
    Wire.begin(26,32);
    M5.begin();
    Serial.begin(115200);
    driver.begin(&Wire, HBRIDGE_ADDR, 26, 32, 100000L); //NOTE: Update Unit H-bridge.h for the correct i2c PINs
}

void loop() {
        for(int i = 0; i < 10; i++){
        driver.setDriverDirection(1); // Set peristaltic pump in forward to take out BR content
        driver.setDriverSpeed8Bits(255); //Run pump in full speed
        Serial.print("Forward pump for 5 secs #: ");
        Serial.println(i);
        delay(5000);
        driver.setDriverSpeed8Bits(0);  //Stop pump 
        Serial.println("Wait for 30 secs");     
        delay(30000);         
        }
        
        driver.setDriverDirection(2); // Set peristaltic pump in reverse to rinse 
        driver.setDriverSpeed8Bits(255);
        Serial.println("Reverse pump for 5 secs #: ");
        delay(5000);
        driver.setDriverSpeed8Bits(0);             
        delay(1000);         
    //Serial.println("VIN IN: " + String(driver.getAnalogInput(_12bit) / 4095.0f * 3.3f / 0.09f));
    //Serial.println("current: " + String(driver.getMotorCurrent())); 
}
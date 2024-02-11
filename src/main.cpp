/*
*******************************************************************************
* Product: Hbridge Unit
* getMotorCurrent() only support in v1.1 function
* Date: 2023/8/9
*******************************************************************************
*/

#include <Arduino.h>
#include "M5Atom.h"
#include "UNIT_HBRIDGE.h"

UNIT_HBRIDGE driver;

void setup() {
    Wire.begin(26,32);
    M5.begin();

    driver.begin(&Wire, HBRIDGE_ADDR, 26, 32, 100000L); //NOTE: Update Unit H-bridge.h for the correct i2c PINs
    
}

void loop() {

        driver.setDriverDirection(1);
        driver.setDriverSpeed8Bits(200);
        delay(3000);
        driver.setDriverSpeed8Bits(255);
        delay(5000);
        driver.setDriverSpeed8Bits(0);             
        delay(3000);  
        driver.setDriverDirection(2);
        driver.setDriverSpeed8Bits(255);
        delay(3000);
        driver.setDriverSpeed8Bits(0);             
        delay(3000);        

    //Serial.println("VIN IN: " + String(driver.getAnalogInput(_12bit) / 4095.0f * 3.3f / 0.09f));
    //Serial.println("current: " + String(driver.getMotorCurrent())); 
}
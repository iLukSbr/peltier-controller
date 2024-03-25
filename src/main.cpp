#include "components.hpp"

#define TEMPERATURE_TARGET 15.f

void setup(){
    #ifdef SERIAL_DEBUG
        Serial.begin(115200);
        while(!Serial);
    #endif
    #ifdef __LCD_HPP__
        lcd = LCD::getInstance();
    #endif
    #ifdef __PELTIER_HPP__
        peltier = Peltier::getInstance();
    #endif
    #ifdef __THERMOMETER_HPP__
        thermometer = Thermometer::getInstance();
    #endif
}

void loop() {
    float temperature = thermometer->getTemperatureCelsius();
    char message[16] = "Peltier: ", s[7] = {0};
    dtostrf(temperature, 5, 2, s);
    strcat(message, s);
    #ifdef SERIAL_DEBUG
        Serial.println(message);
    #endif
    #ifdef __LCD_HPP__
        lcd->print(temperature);
    #endif
    if(temperature > TEMPERATURE_TARGET){
        peltier->on();
    }
    else{
        peltier->off();
    }
    delay(1000);
}
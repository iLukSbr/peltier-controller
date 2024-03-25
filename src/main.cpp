#include "components.hpp"

#define ALWAYS_ON
#define TEMPERATURE_TARGET 15.f

bool is_on;

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
    peltier->on();
    is_on = true;
}

void loop() {
    float temperature = thermometer->getTemperatureCelsius();
    char message[18], tempString[8], degreeSymb[4] = {' ',(char)223,'C','\0'};
    dtostrf(temperature, 5, 2, tempString);
    strcpy(message, "Peltier ");
    strcat(message, tempString);
    strcat(message, degreeSymb);
    #ifdef SERIAL_DEBUG
        Serial.println(temperature);
    #endif
    #ifdef __LCD_HPP__
        lcd->print(message);
    #endif
    #ifndef ALWAYS_ON
        if(temperature >= TEMPERATURE_TARGET && !is_on){
            peltier->on();
            is_on = true;
        }
        else if(temperature < TEMPERATURE_TARGET && is_on){
            peltier->off();
            is_on = false;
        }
    #endif
    delay(1000);
}
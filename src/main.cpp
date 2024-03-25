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
    char message[18], tempString[8], degreeSymb[2] = {(char)223,'\0'};
    dtostrf(temperature, 5, 2, tempString);
    strcpy(message, "Peltier ");
    strcat(message, tempString);
    strcat(message, " ");
    strcat(message, degreeSymb);
    strcat(message, "C");
    #ifdef SERIAL_DEBUG
        Serial.println(temperature);
    #endif
    #ifdef __LCD_HPP__
        lcd->print(message);
    #endif
    if(temperature > TEMPERATURE_TARGET){
        peltier->on();
    }
    else{
        peltier->off();
    }
    delay(1000);
}
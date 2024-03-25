#include "components.hpp"

#define TEMPERATURE_TARGET 15.f

void setup(){
    Wire.begin();
}

void loop() {

    float temperature = thermometer->getTemperatureCelsius();
    String message = "Peltier: ";
    message += temperature;
    lcd->print(temperature);
    if(temperature > TEMPERATURE_TARGET){
        peltier->on();
    }
    else{
        peltier->off();
    }
    delay(1000);
}
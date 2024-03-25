#include "Thermometer.hpp"

Thermometer* Thermometer::instance = nullptr;

Thermometer* Thermometer::getInstance(){
	if(!instance){
		instance = new Thermometer();
	}
	return instance;
}

Thermometer::Thermometer():
	thermocouple(new MAX6675(THERMOMETER_SCK_PIN, THERMOMETER_CS_PIN, THERMOMETER_SO_PIN))
{
}

float Thermometer::getTemperatureCelsius(){
	return thermocouple->readCelsius();
}

float Thermometer::getTemperatureFahrenheit(){
	return thermocouple->readFahrenheit();
}
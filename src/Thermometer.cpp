#include "Thermometer.hpp"

Thermometer* Thermometer::instance = nullptr;

Thermometer* Thermometer::getInstance(){
	if(!instance){
		instance = new Thermometer();
	}
	return instance;
}

Thermometer::Thermometer():
	thermocouple(new MAX6675(THERMOMETER_CS_PIN, &SPI))
{
	SPI.begin();
	thermocouple->begin();
	thermocouple->setSPIspeed(9600);
}

float Thermometer::getTemperatureCelsius(){
	thermocouple->read();
	return thermocouple->getTemperature();
}
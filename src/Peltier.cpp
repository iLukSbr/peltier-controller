#include "Peltier.hpp"

Peltier* Peltier::instance = nullptr;

Peltier* Peltier::getInstance(){
	if(!instance){
		instance = new Peltier();
	}
	return instance;
}

Peltier::Peltier()
{
    pinMode(PELTIER_MOSFET_GATE_PIN, OUTPUT);
    this->off();
}

void Peltier::on(){
    digitalWrite(PELTIER_MOSFET_GATE_PIN, HIGH);
}

void Peltier::off(){
    digitalWrite(PELTIER_MOSFET_GATE_PIN, LOW);
}
#include "LCD.hpp"

LCD* LCD::instance = nullptr;

LCD* LCD::getInstance(){
	if(!instance){
		instance = new LCD();
	}
	return instance;
}

LCD::LCD():
	lcd(new LiquidCrystal_PCF8574(0x27))
{
	Wire.begin();
	Wire.beginTransmission(0x27);
	byte error = Wire.endTransmission();
	while(error != 0){// no lcd found
		#ifdef SERIAL_DEBUG
			Serial.println(F("LCD not found..."));
		#endif
		Wire.beginTransmission(0x27);
		error = Wire.endTransmission();
		delay(1000);
	}
	lcd->begin(16, 2);// initialize the lcd
}

void LCD::off(){
	lcd->clear();
	lcd->setBacklight(0);
	lcd->home();
	lcd->noDisplay();
}
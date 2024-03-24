#include "MAX6675.hpp"


MAX6675::MAX6675(uint8_t cs, uint8_t sclk, uint8_t dout)
	: cs(cs), sclk(sclk), dout(dout)
{
	pinMode(cs, OUTPUT);
	pinMode(sclk, OUTPUT);
	pinMode(dout, INPUT);

	digitalWrite(cs, HIGH);
}

int32_t MAX6675::read()
{
	int32_t result = -1;

	digitalWrite(cs, LOW);

	for (int i = 0; i < 16; i++) {
		digitalWrite(sclk, LOW);
		delayMicroseconds(5);
		result = (result << 1) | digitalRead(dout);
		digitalWrite(sclk, HIGH);
		delayMicroseconds(5);
	}

	digitalWrite(cs, HIGH);

	return result;
}

float MAX6675::readCelsius()
{
	int32_t adc = read();

	if (adc == -1) {
		return NAN;
	}

	return adc * 0.25;
}



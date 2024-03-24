#include <Arduino.h>

#include "components.hpp"

LCD lcd;
MAX6675 thermocouple(10, 11, 12);
Peltier peltier(9);

void setup() {
    lcd.begin();
    peltier.begin();
}

void loop() {
    float temperature = thermocouple.readCelsius();
    if (temperature > 50) {
        peltier.setPower(map(temperature, 50, 100, 0, 100));
    } else {
        peltier.off();
    }
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Temperature: ");
    lcd.print(temperature);
    lcd.print(" C");
    delay(1000);
}
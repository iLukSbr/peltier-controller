#define __PELTIER_HPP__

class Peltier
{
public:
    Peltier(int pwmPin, int enablePin, int thermoPin);

    void begin(int dutyCycle);
    void setDutyCycle(int dutyCycle);
    void enable();
    void disable();
    int getDutyCycle();
    int getThermoTemperature();

private:
    int _pwmPin;
    int _enablePin;
    int _thermoPin;
    int _dutyCycle;
};
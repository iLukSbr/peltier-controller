#include "Peltier.hpp"

<<<<<<<<<<<<<<  ✨ Codeium Command ⭐ >>>>>>>>>>>>>>>>

void Peltier::begin()
{
    pinMode(pin_, OUTPUT);
}

void Peltier::setPower(int power)
{
    power = constrain(power, 0, 100);
    analogWrite(pin_, map(power, 0, 100, 0, 255));
}

void Peltier::off()
{
    analogWrite(pin_, 0);
}
<<<<<<<  4cc8d347-ffa7-4f29-93e2-52c20f17bd94  >>>>>>>
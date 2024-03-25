#include "pch.hpp"

#include "LCD.hpp"
#include "Thermometer.hpp"
#include "Peltier.hpp"

#ifdef __LCD_HPP__
    LCD* lcd = nullptr;
#endif
#ifdef __PELTIER_HPP__
    Peltier* peltier = nullptr;
#endif
#ifdef __THERMOMETER_HPP__
    Thermometer* thermometer = nullptr;
#endif
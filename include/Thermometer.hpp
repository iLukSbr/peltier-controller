#include "pch.hpp"

// MAX6675 thermocouple sensor
#include <max6675.h>

#ifndef __THERMOMETER_HPP__
    #define __THERMOMETER_HPP__

    #define THERMOMETER_SCK_PIN 13
    #define THERMOMETER_SO_PIN 12
    #define THERMOMETER_CS_PIN 10
    
    class Thermometer{
        public:
            static Thermometer* getInstance();
            
            float getTemperatureCelsius();
            float getTemperatureFahrenheit();

        private:
            Thermometer();

            Thermometer(Thermometer const&) = delete;// prevent copy construction

            Thermometer(Thermometer&&) = delete;// prevent move construction

            Thermometer& operator=(Thermometer const&) = delete;// prevent copy assignment

            Thermometer& operator=(Thermometer &&) = delete;// prevent move assignment

            ~Thermometer() = default;// add default destructor

            static Thermometer* instance;

            MAX6675* thermocouple;
    };
#endif

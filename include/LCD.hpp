#include "pch.hpp"

#ifndef __LCD_HPP__
    #define __LCD_HPP__

    #include <Wire.h>
    #include <LiquidCrystal_PCF8574.h>

    class LCD{
        public:
            static LCD* getInstance();

            template<typename T>
            void print(const T& message) {
                lcd->display();
                lcd->setBacklight(255);
                lcd->home();
                lcd->clear();
                lcd->print(message);
            }

            void off();

        private:
            LCD();

            LCD(LCD const&) = delete;// prevent copy construction

            LCD(LCD&&) = delete;// prevent move construction

            LCD& operator=(LCD const&) = delete;// prevent copy assignment

            LCD& operator=(LCD &&) = delete;// prevent move assignment

            ~LCD() = default;// add default destructor

            static LCD* instance;

            LiquidCrystal_PCF8574* lcd;
    };
#endif
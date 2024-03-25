#include "pch.hpp"

#ifndef __PELTIER_HPP__
    #define __PELTIER_HPP__

    #define PELTIER_MOSFET_GATE_PIN 3

    class Peltier{
        public:
            static Peltier* getInstance();
            
            void on();
            void off();

        private:
            Peltier();

            Peltier(Peltier const&) = delete;// prevent copy construction

            Peltier(Peltier&&) = delete;// prevent move construction

            Peltier& operator=(Peltier const&) = delete;// prevent copy assignment

            ~Peltier() = default;// add default destructor

            static Peltier* instance;
    };
#endif
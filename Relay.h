#ifndef _USER_Relay_H_
#define _USER_Relay_H_

#include <arduino.h>


class Relay {
    public:
        Relay(uint8_t pin=12);
        bool isOn();
        void turn();
        void turnOff();
        void turnOn();
    private:
        uint8_t pin;
        bool isOff;
};

#endif

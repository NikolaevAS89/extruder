#include "Relay.h"

Relay::Relay(uint8_t pin) {
    this->pin = pin;
    this->isOff = true;
    pinMode(this->pin, OUTPUT);
    digitalWrite(this->pin, LOW);
}

void Relay::turn() {
  if(this->isOn()) {
    this->turnOff();
  } else {
    this->turnOn();
  }
}

bool Relay::isOn() {
  return !this->isOff;
}

void Relay::turnOff() {
  if(this->isOn()) {
    digitalWrite(this->pin,LOW);
  }
  this->isOff = true;
}

void Relay::turnOn() {
  if(this->isOff) {
    digitalWrite(this->pin,HIGH);
  }
  this->isOff = false;
}

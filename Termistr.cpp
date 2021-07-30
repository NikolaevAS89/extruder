#include "Termistr.h"


Termistr::Termistr(uint8_t pin, double b, double t0) {
	this->pin = pin;
  this->b = b;
  this->t0 = t0;
  pinMode( this->pin, INPUT );
}

Termistr::~Termistr() {
}

double Termistr::getValue() {
    this->nextTime = this->nextTime + this->period;
    double t = (double) analogRead( this->pin );
    double d2 = THERMISTOR_R * ( 1023.0 - t );
    double d1 = 1023.0*Rn + t * SERIAL_R;
    return (this->t0*this->b /(this->b + this->t0 *(log(d1)-log(d2)))) - 273.15;
}

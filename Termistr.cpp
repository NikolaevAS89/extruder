#include "Termistr.h"


Termistr::Termistr(uint8_t pin, uint32_t period, double b, double t0) {
	this->pin = pin;
	this->period = period;
	this->b = b;
	this->t0 = t0;
	this->startMs = 0;
  this->delta = 0;
  this->last = 0;
  this->values = new double[N_V];
  pinMode( this->pin, INPUT );
}

Termistr::~Termistr() {
}

void Termistr::getCels() {
    return this->last;  
}

void Termistr::loop() {
    uint32_t ms = millis();
    uint32_t bound = this->startMs + this->period;
    if(ms >= bound) {
  		this->startMs = ms;
  		/*double t = (double) analogRead( this->pin );
  		double r_r0 = ( t/1023.0 );
      double d1 = this->b + this->t0*(log(r_r0) - log(1.0 - r_r0));
      double d2 = this->b * this->t0;
  		double cels = d2 / d1 - 273.15;
      double delta = this->last-cels;
      if(abs(delta-this->delta)<2) {
  	    this->fireEvent(cels);
      }
      this->last = cels;*/
      double t = (double) analogRead( this->pin );
      double d2 = THERMISTOR_R*( 1023.0 - t );
      double d1 = 1023.0*Rn + t*SERIAL_R;
      double cels = (this->t0*this->b /(this->b + this->t0 *(log(d1)-log(d2)))) - 273.15;
      this->fireEvent(cels);      
	  }
}

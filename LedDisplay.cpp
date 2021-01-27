#include "LedDisplay.h"


LedDisplay::LedDisplay() {
	this->lcd = new LiquidCrystal_I2C(0x27, 16, 2);
    this->lcd->init();
    this->lcd->backlight();
    this->curTemperature = 0;
    this->maxTemperature = 0;
    this->hasChange = true;
    this->buffer = new char[16];
}

LedDisplay::~LedDisplay() {
	delete this->lcd;
}

uint16_t LedDisplay::getCurTemperature() {
  return this->curTemperature;
}

uint16_t LedDisplay::getMaxTemperature() {
  return this->maxTemperature;
}

void LedDisplay::setCurTemperature(uint16_t temperature) {
	if(temperature != this->curTemperature) {
		this->curTemperature = temperature;
		this->hasChange = true;
	}
}

void LedDisplay::setMaxTemperature(uint16_t temperature) {
	if(temperature != this->maxTemperature) {
		this->maxTemperature = temperature;
		this->hasChange = true;
	}
}

void LedDisplay::loop() {
    if(this->hasChange) {
    	sprintf(this->buffer, "current: %7d", this->curTemperature);
	    this->lcd->setCursor(0, 0);
	    this->lcd->print(this->buffer);
    	sprintf(this->buffer, "maximum: %7d", this->maxTemperature);
    	this->lcd->setCursor(0, 1);
	    this->lcd->print(this->buffer);
		  this->hasChange = false;
    }
}

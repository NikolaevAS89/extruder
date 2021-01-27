#ifndef _LED_DISPLAY_H_
#define _LED_DISPLAY_H_

#include <arduino.h>
#include <LiquidCrystal_I2C.h>

extern bool isDebug;

class LedDisplay {
  private:
    LiquidCrystal_I2C *lcd;
    uint16_t curTemperature;
    uint16_t maxTemperature;
    char* buffer;
    bool hasChange;
  public:
    LedDisplay();
    ~LedDisplay();

    void setCurTemperature(uint16_t temperature);
    void setMaxTemperature(uint16_t temperature);
    
    uint16_t getCurTemperature();
    uint16_t getMaxTemperature();

    void loop();
};

#endif

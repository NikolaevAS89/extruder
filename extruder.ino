#include "Termistr.h"
#include "Button.h"
#include "LedDisplay.h"
#include "Relay.h"
#include "Scheduler.h"

#ifndef PIN_RELAY
#define PIN_RELAY 12
#endif

#ifndef PIN_TEMP_UP
#define PIN_TEMP_UP 4
#endif
#ifndef PIN_TEMP_DOWN
#define PIN_TEMP_DOWN 7
#endif

LedDisplay *lcd;
Termistr *termistr;
Button *tempUp;
Button *tempDown;
Relay *relay;
Scheduler* scheduler;

void buttonTempUpClick(BUTTON_CLICK_EVENT event) {
    Serial.print("buttonTempUpClick\n");
    Serial.print(event);
    uint16_t t = lcd->getMaxTemperature();
    t = (t<100)?100:(t>=300)?300:t+5;
    lcd->setMaxTemperature(t);
}
void buttonTempDownClick(BUTTON_CLICK_EVENT event) {
    Serial.print("buttonTempDownClick\n");
    Serial.print(event);
    uint16_t t = lcd->getMaxTemperature();
    t = (t<=100)?0:t-5;
    lcd->setMaxTemperature(t);
}

void updateTemperature() {
    Serial.print("updateTemperature\n");
    Serial.print(newTemperature);
    Serial.print("\n");
    uint16_t t = newTemperature;
    uint16_t t0 = lcd->getMaxTemperature();
    Serial.print(t0);
    Serial.print("\n");
    lcd->setCurTemperature(t);
    if(t0>t){
        relay->turnOn();
        Serial.print("on\n");
    } else {
        relay->turnOff();
        Serial.print("off\n");
    }
}

void setup() {
    Serial.begin(9600);
    relay = new Relay(PIN_RELAY);
    
    lcd = new LedDisplay();

    termistr = new Termistr();

    scheduler = new Scheduler();

    Job* job = new Job(1000, updateTemperature);
    scheduler->addJob(job);
    
    tempDown = new Button(PIN_TEMP_DOWN);
    tempDown->addListener(buttonTempDownClick);
    
    tempUp = new Button(PIN_TEMP_UP);
    tempUp->addListener(buttonTempUpClick);
}

void loop() {
    scheduler->loop();
    tempDown->loop();
    tempUp->loop();
    lcd->loop();
}

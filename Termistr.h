#ifndef _USER_Termistr_H_
#define _USER_Termistr_H_

#include <arduino.h>

extern bool isDebug;

#define B 3950 // B-коэффициент
#define SERIAL_R 102000 // сопротивление последовательного резистора, 102 кОм
#define THERMISTOR_R 100000 // номинальное сопротивления термистора, 100 кОм
#define NOMINAL_T (25.0 + 273.15) // номинальная температура (при которой TR = 100 кОм)
#define Rn 100 //RC filter resistor
#define N_V 10

class Termistr {
  private:
    uint8_t pin;
    
    double b;
    double t0;
    double last;
    double delta;
    double *values;
    uint32_t startMs;
    uint32_t period;
    TNode *listeners;
  public:
    Termistr(uint8_t pin=A0, uint32_t period=1000, double b=4092.0, double t0=298.15);
    ~Termistr();
    double getCels();
    void loop();
};

#endif

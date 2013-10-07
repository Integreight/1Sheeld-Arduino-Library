/*
  ConvertPWM.h - Library for converting PWM signals to analog .
  Created by Mustafa Fayez, May 27, 2013.
  Released into the public domain.
*/


#ifndef ConvertPWM_h
#define ConvertPWM_h

#include "Arduino.h"
class ConvertPWM
{
public:
    ConvertPWM();
    unsigned long readValue(int pin);
private:
    unsigned long PeriodCalculation(unsigned long period);
    unsigned long ReadPWM ();
    int _pin ;
};

extern ConvertPWM PWM;
#endif
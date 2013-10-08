/*
  ReadPWMClass.h - Library for converting PWM signals to analog .
  Created by Mustafa Fayez, May 27, 2013.
  Released into the public domain.
*/


#ifndef ReadPWMClass_h
#define ReadPWMClass_h

#include "Arduino.h"
class ReadPWMClass
{
public:
    ReadPWMClass();
    unsigned long readValue(int pin);
private:
    unsigned long PeriodCalculation(unsigned long period);
    unsigned long ReadPWM ();
    int _pin ;
};

extern ReadPWMClass PWM;
#endif
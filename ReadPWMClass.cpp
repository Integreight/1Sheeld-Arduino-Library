/*
  ReadPWMClass.h - Library for converting PWM signals to analog .
  Created by Mustafa Fayez, May 27, 2013.
  Released into the public domain.
*/

#include "Arduino.h"
#include "ReadPWMClass.h"

ReadPWMClass::ReadPWMClass() {}
unsigned long ReadPWMClass::PeriodCalculation(unsigned long period)
{
    return ((period / 7.8431372549019607843137254901961) + 1);
}
unsigned long ReadPWMClass::ReadPWM ()
{
    return (pulseIn(_pin, HIGH));
}
unsigned long ReadPWMClass::readValue (int pin)
{
    //pinMode(pin, INPUT);
    _pin = pin;
    return (PeriodCalculation(ReadPWM()));
}

ReadPWMClass PulseWidthModulation;
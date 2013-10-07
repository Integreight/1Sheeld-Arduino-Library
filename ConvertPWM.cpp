/*
  ConvertPWM.h - Library for converting PWM signals to analog .
  Created by Mustafa Fayez, May 27, 2013.
  Released into the public domain.
*/

#include "Arduino.h"
#include "ConvertPWM.h"

ConvertPWM::ConvertPWM() {}
unsigned long ConvertPWM::PeriodCalculation(unsigned long period)
{
    return ((period / 7.8431372549019607843137254901961) + 1);
}
unsigned long ConvertPWM::ReadPWM ()
{
    return (pulseIn(_pin, HIGH));
}
unsigned long ConvertPWM::readValue (int pin)
{
    //pinMode(pin, INPUT);
    _pin = pin;
    return (PeriodCalculation(ReadPWM()));
}

ConvertPWM PWM;
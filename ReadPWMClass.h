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
    unsigned long getValue(int );
private:
    double period;
    double duty;
    double fraction;

};

extern ReadPWMClass PulseWidthModulation;
#endif
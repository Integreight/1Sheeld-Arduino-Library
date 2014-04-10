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
    unsigned char getValue(int );
    void setOnChange(void (*)());
private:
	unsigned char pwm_out;
    double period;
    double duty;
    double fraction;
    bool isCallBackAssigned;
    void (*changeCallBack)();

};

extern ReadPWMClass PulseWidthModulation;
#endif
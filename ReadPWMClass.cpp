/*
  ReadPWMClass.h - Library for converting PWM signals to analog .
  Created by Mustafa Fayez, May 27, 2013.
  Released into the public domain.
*/

#include "Arduino.h"
#include "ReadPWMClass.h"

ReadPWMClass::ReadPWMClass() 
{}

unsigned long ReadPWMClass::getValue(int pin)
{
	period=0;
	duty=0;
	fraction=0;

	period=(double)pulseIn(pin,HIGH)+(double)pulseIn(pin,LOW);
	duty=(double)pulseIn(pin,HIGH);
	fraction=duty/period;
	return ((floor)(fraction)*(255));
}

ReadPWMClass PulseWidthModulation;
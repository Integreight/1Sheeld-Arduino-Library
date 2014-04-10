/*
  ReadPWMClass.h - Library for converting PWM signals to analog .
  Created by Mustafa Fayez, May 27, 2013.
  Released into the public domain.
*/

#include "Arduino.h"
#include "ReadPWMClass.h"


ReadPWMClass::ReadPWMClass() 
{
	isCallBackAssigned=false;
}

unsigned char ReadPWMClass::getValue(int pin)
{
	pwm_out =0;
	period=0;
	duty=0;
	fraction=0;
	period=(double)pulseIn(pin,HIGH)+(double)pulseIn(pin,LOW);
	duty=(double)pulseIn(pin,HIGH);
	fraction=duty/period;
	pwm_out=(unsigned char)(ceil)(fraction*255);
	if(isCallBackAssigned)
	{
		(*changeCallBack)();
	}
	return (pwm_out);
}

void ReadPWMClass::setOnChange(void (*userFunction)())
{
	changeCallBack=userFunction;
	isCallBackAssigned=true;
}
ReadPWMClass PulseWidthModulation;
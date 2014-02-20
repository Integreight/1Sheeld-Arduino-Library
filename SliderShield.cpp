#include "OneSheeld.h"
#include "SliderShield.h"

SliderShield::SliderShield()
{
	value=0x00;
	callBack=false;
}
byte SliderShield::getValue()
{
	return value;
}


void SliderShield::processData()
{
	value= OneSheeld.getArgumentData(0)[0];
	if(callBack)
		(*changeCallBack)(value);
}

void SliderShield::setOnChange(void (*userFunction)(byte))
{
	changeCallBack=userFunction;
	callBack=true;
}

SliderShield Slider;
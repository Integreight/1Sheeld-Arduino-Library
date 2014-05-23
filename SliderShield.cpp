#include "OneSheeld.h"
#include "SliderShield.h"

SliderShield::SliderShield()
{
	value=0x00;
	isCallBackAssigned=false;
}
byte SliderShield::getValue()
{
	return value;
}


void SliderShield::processData()
{
	byte functionId= OneSheeld.getFunctionId();
	if(functionId==SLIDER_VALUE)
		{
			value= OneSheeld.getArgumentData(0)[0];
			if(isCallBackAssigned)
				(*changeCallBack)(value);
		}
}

void SliderShield::setOnValueChange(void (*userFunction)(byte sliderValue))
{
	changeCallBack=userFunction;
	isCallBackAssigned=true;
}

SliderShield Slider;
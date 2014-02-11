#include "OneSheeld.h"
#include "TemperatureShield.h"



TemperatureShield::TemperatureShield()
{
	value=0xff;
	callBack=false;
}

signedvalue TemperatureShield::getDegree()
{
	return value;
}

void TemperatureShield::processData()
{
	value=OneSheeld.getArgumentData(0)[0];
	if(callBack)
		(*changeOnCallBack)(value);
}

void TemperatureShield::setOnChange(void(*userFunction)(signedvalue))
{
	changeOnCallBack=userFunction;
	callBack=true;
}

TemperatureShield Temp;
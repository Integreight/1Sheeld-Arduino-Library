#include "OneSheeld.h"
#include "TemperatureSensorShield.h"



TemperatureSensorShield::TemperatureSensorShield()
{
	value=0xff;
	callBack=false;
}

char TemperatureSensorShield::getDegree()
{
	return value;
}

void TemperatureSensorShield::processData()
{
	value=OneSheeld.getArgumentData(0)[0];
	if(callBack)
		(*changeOnCallBack)(value);
}

void TemperatureSensorShield::setOnChange(void(*userFunction)(char))
{
	changeOnCallBack=userFunction;
	callBack=true;
}

TemperatureSensorShield TemperatureSensor;
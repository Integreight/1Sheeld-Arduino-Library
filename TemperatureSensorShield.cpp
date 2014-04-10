#include "OneSheeld.h"
#include "TemperatureSensorShield.h"



TemperatureSensorShield::TemperatureSensorShield()
{
	value=0xff;
	isCallBackAssigned=false;
}

char TemperatureSensorShield::getValue()
{
	return value;
}

void TemperatureSensorShield::processData()
{
	byte functionId =OneSheeld.getFunctionId();
	if(functionId==TEMPERATURE_VALUE)
	{
		value=OneSheeld.getArgumentData(0)[0];
		if(isCallBackAssigned)
			(*changeOnCallBack)();
	}
}

void TemperatureSensorShield::setOnChange(void(*userFunction)())
{
	changeOnCallBack=userFunction;
	isCallBackAssigned=true;
}

TemperatureSensorShield TemperatureSensor;
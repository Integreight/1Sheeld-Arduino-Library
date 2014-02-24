#include "OneSheeld.h"
#include "ProximitySensorShield.h"





ProximitySensorShield::ProximitySensorShield()
{
	value=0x00;
	callBack=false;
}

byte ProximitySensorShield::getValue()
{
	return value;
}

void ProximitySensorShield::processData()
{
	byte functionId =OneSheeld.getFunctionId();
	if(functionId==PROXIMITY_VALUE)
	{
		value=OneSheeld.getArgumentData(0)[0];
		if (callBack)
		(*changeCallBack)(value);
	}
}

void ProximitySensorShield::setOnChange(void (*userFunction)(byte))
{
	changeCallBack=userFunction;
	callBack=true;
}
ProximitySensorShield ProximitySensor;
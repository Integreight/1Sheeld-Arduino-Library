#include "OneSheeld.h"
#include "ProximitySensorShield.h"





ProximitySensorShield::ProximitySensorShield()
{
	value=0x00;
	isCallBackAssigned=false;
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
		if (isCallBackAssigned)
		(*changeCallBack)();
	}
}

void ProximitySensorShield::setOnChange(void (*userFunction)())
{
	changeCallBack=userFunction;
	isCallBackAssigned=true;
}
ProximitySensorShield ProximitySensor;
#include "OneSheeld.h"
#include "LightSensorShield.h"


LightSensorShield::LightSensorShield()
{
	value=0;
	isCallBackAssigned=false;
}

unsigned long LightSensorShield::getValue()
{
	
	return value;
	
}

void LightSensorShield::processData()
{
	byte functionId =OneSheeld.getFunctionId();
	if(functionId==LIGHT_VALUE)
	{
		value=0;
		data[0]=OneSheeld.getArgumentData(0)[0];
		data[1]=OneSheeld.getArgumentData(0)[1];
		data[2]=OneSheeld.getArgumentData(0)[2];
		value|=data[0];
		value|=(data[1]<<8);
		value|=(data[2]<<16);
		if(isCallBackAssigned)
		{
			(*changeCallBack)(value);
		}
	}
}

void LightSensorShield::setOnChange(void (*userFunction)(unsigned long lightValue))
{
	changeCallBack=userFunction;
	isCallBackAssigned=true;
}

LightSensorShield LightSensor;
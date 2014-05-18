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
		getfloat.data[0]=OneSheeld.getArgumentData(0)[0];
		getfloat.data[1]=OneSheeld.getArgumentData(0)[1];
		getfloat.data[2]=OneSheeld.getArgumentData(0)[2];
		getfloat.data[3]=0;
		value=getfloat.num;
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
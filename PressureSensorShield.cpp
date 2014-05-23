#include "OneSheeld.h"
#include "PressureSensorShield.h"

PressureSensorShield::PressureSensorShield()
{
	value=0;
	isCallBackAssigned=false;
}

unsigned long PressureSensorShield::getValue()
{
	
	return value;
	
}
//two bytes to be received 
void PressureSensorShield::processData()
{
	byte functionId =OneSheeld.getFunctionId();
	if(functionId==PRESSURE_VALUE)
	{
		value=0;
		data[0]=OneSheeld.getArgumentData(0)[0];
		data[1]=OneSheeld.getArgumentData(0)[1];
		value|=data[0];
		value|=(data[1]<<8);

		if(isCallBackAssigned)
		{
			(*changeCallBack)(value);
		}
	}
}

void PressureSensorShield::setOnValueChange(void (*userFunction)(unsigned long pressureValue))
{
	changeCallBack=userFunction;
	isCallBackAssigned=true;
}

PressureSensorShield PressureSensor;
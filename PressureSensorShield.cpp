#include "OneSheeld.h"
#include "PressureSensorShield.h"

PressureSensorShield::PressureSensorShield()
{
	value=0;
}

unsigned long PressureSensorShield::getPressure()
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
		value|=(unsigned long)data[0];
		value|=(unsigned long)(data[1]<<8);
	}
}

PressureSensorShield PressureSensor;
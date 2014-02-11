#include "OneSheeld.h"
#include "LightSensorShield.h"
#include "HardwareSerial.h"



LightSensorShield::LightSensorShield()
{
	value=0;
}

unsigned long LightSensorShield::getValue()
{
	
	return value;
	
}

void LightSensorShield::processData()
{
	
	data[0]=OneSheeld.getArgumentData(0)[0];
	data[1]=OneSheeld.getArgumentData(0)[1];
	data[2]=OneSheeld.getArgumentData(0)[2];
	value|=(unsigned long)data[2];
	value|=(unsigned long)(data[1]<<8);
	value|=(unsigned long)(data[0]<<16);
}

LightSensorShield Light;
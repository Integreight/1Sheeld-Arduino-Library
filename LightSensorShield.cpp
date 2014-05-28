/*

  Project:       1Sheeld Library 
  File:          LightSensorShield.cpp
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/

#include "OneSheeld.h"
#include "LightSensorShield.h"

//Class Constructor
LightSensorShield::LightSensorShield()
{
	value=0;
	isCallBackAssigned=false;
}
//Light Getter 
unsigned long LightSensorShield::getValue()
{
	
	return value;
	
}
//Light Input Data Processing
void LightSensorShield::processData()
{
	//Checking Function-ID
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
		//Users Function Invoked
		if(isCallBackAssigned)
		{
			(*changeCallBack)(value);
		}
	}
}
//Users Function Setter 
void LightSensorShield::setOnValueChange(void (*userFunction)(unsigned long lightValue))
{
	changeCallBack=userFunction;
	isCallBackAssigned=true;
}

//Instantiating Object
LightSensorShield LightSensor;
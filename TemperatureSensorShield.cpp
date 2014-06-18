/*

  Project:       1Sheeld Library 
  File:          TemperatureSensorShield.cpp
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/

#include "OneSheeld.h"
#include "TemperatureSensorShield.h"


//Class Constructor
TemperatureSensorShield::TemperatureSensorShield()
{
	value=0xff;
	isCallBackAssigned=false;
}
//Temperature Getter 
char TemperatureSensorShield::getValue()
{
	return value;
}
//TemperatureSensor Input Data Processing
void TemperatureSensorShield::processData()
{
	//Checking Function-ID
	byte functionId =OneSheeld.getFunctionId();

	if(functionId==TEMPERATURE_VALUE)
	{
		value=OneSheeld.getArgumentData(0)[0];
		//Users Function Invocation
		if(isCallBackAssigned)
			(*changeOnCallBack)(value);
	}
}
//Users Function Setter
void TemperatureSensorShield::setOnValueChange(void(*userFunction)(char temp))
{
	changeOnCallBack=userFunction;
	isCallBackAssigned=true;
}

float TemperatureSensorShield::getAsFahrenheit()
{
	float fahrenheit;
	fahrenheit = (float)value*(1.8)+32;
	return value;
}
//Instatntiating Object
TemperatureSensorShield TemperatureSensor;
/*

  Project:       1Sheeld Library 
  File:          TemperatureSensorShield.cpp
                 
  Version:       1.1

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/
#define FROM_ONESHEELD_LIBRARY
#include "OneSheeld.h"
#include "TemperatureSensorShield.h"


//Class Constructor
TemperatureSensorShield::TemperatureSensorShield() : ShieldParent(TEMPERATURE_ID)
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
	byte functionId =getOneSheeldInstance().getFunctionId();

	if(functionId==TEMPERATURE_VALUE)
	{
		value=getOneSheeldInstance().getArgumentData(0)[0];
		//Users Function Invocation
		if(isCallBackAssigned && !isInACallback())
		{
			enteringACallback();
			(*changeOnCallBack)(value);
			exitingACallback();
		}
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
	return fahrenheit;
}


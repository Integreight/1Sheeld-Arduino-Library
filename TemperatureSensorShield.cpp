/*

  Project:       1Sheeld Library 
  File:          TemperatureSensorShield.cpp
                 
  Version:       1.1

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

void TemperatureSensorShield::select()
{
	OneSheeld.sendPacket(TEMPERATURE_ID,0,TEMPERATURE_SELECT_SHIELD,0);
}

void TemperatureSensorShield::unselect()
{
	OneSheeld.sendPacket(TEMPERATURE_ID,0,TEMPERATURE_UNSELECT_SHIELD,0);
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
	else if(functionId == TEMPERATURE_CHECK_SELECTED)
	{
		(*selectedCallBack)();
	}
}
//Users Function Setter
void TemperatureSensorShield::setOnValueChange(void(*userFunction)(char temp))
{
	changeOnCallBack=userFunction;
	isCallBackAssigned=true;
}

void TemperatureSensorShield::setOnSelected(void (*userFunction)(void))
{
	selectedCallBack= userFunction;
}
float TemperatureSensorShield::getAsFahrenheit()
{
	float fahrenheit;
	fahrenheit = (float)value*(1.8)+32;
	return value;
}
//Instatntiating Object
TemperatureSensorShield TemperatureSensor;
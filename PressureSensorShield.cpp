/*

  Project:       1Sheeld Library 
  File:          PressureSensorShield.cpp
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/

#include "OneSheeld.h"
#include "PressureSensorShield.h"

//Class Constructor
PressureSensorShield::PressureSensorShield()
{
	value=0;
	isCallBackAssigned=false;
}
//Pressure Getter
unsigned long PressureSensorShield::getValue()
{
	
	return value;
	
}
void PressureSensorShield::select()
{
	OneSheeld.sendPacket(PRESSURE_ID,0,PRESSURE_SELECT_SHIELD,0);
}

void PressureSensorShield::unselect()
{
	OneSheeld.sendPacket(PRESSURE_ID,0,PRESSURE_UNSELECT_SHIELD,0);
}
//PressureSensor Input Data Processing 
void PressureSensorShield::processData()
{
	//Checking Function-ID
	byte functionId =OneSheeld.getFunctionId();
	if(functionId==PRESSURE_VALUE)
	{
		value=0;
		data[0]=OneSheeld.getArgumentData(0)[0];
		data[1]=OneSheeld.getArgumentData(0)[1];
		value|=data[0];
		value|=(data[1]<<8);
		//Users Function Invoked
		if(isCallBackAssigned)
		{
			(*changeCallBack)(value);
		}
	}
	else if(functionId == PRESSURE_CHECK_SELECTED)
	{
		(*selectedCallBack)();
	}
}
//Users Function Setter
void PressureSensorShield::setOnValueChange(void (*userFunction)(unsigned long pressureValue))
{
	changeCallBack=userFunction;
	isCallBackAssigned=true;
}

void PressureSensorShield::setOnSelected(void (*userFunction)(void))
{
	selectedCallBack=userFunction;
}
//Instatntiating Object
PressureSensorShield PressureSensor;
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

void LightSensorShield::select()
{
	OneSheeld.sendPacket(LIGHT_ID,0,LIGHT_SELECT_SHIELD,0);	
}

void LightSensorShield::unselect()
{
	OneSheeld.sendPacket(LIGHT_ID,0,LIGHT_UNSELECT_SHIELD,0);	
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
	else if (functionId == LIGHT_CHECK_SELECTED)
	{
		(*selectedCallBack)();
	}
}
//Users Function Setter 
void LightSensorShield::setOnValueChange(void (*userFunction)(unsigned long lightValue))
{
	changeCallBack=userFunction;
	isCallBackAssigned=true;
}

void LightSensorShield::setOnSelected(void (*userFunction)(void))
{
	selectedCallBack=userFunction;
}
//Instantiating Object
LightSensorShield LightSensor;
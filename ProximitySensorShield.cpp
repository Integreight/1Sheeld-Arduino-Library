/*

  Project:       1Sheeld Library 
  File:          ProximitySensorShield.cpp
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/

#include "OneSheeld.h"
#include "ProximitySensorShield.h"


//Class Constructor
ProximitySensorShield::ProximitySensorShield()
{
	value=0x00;
	isCallBackAssigned=false;
}
//Proximity Getter 
byte ProximitySensorShield::getValue()
{
	return value;
}

void ProximitySensorShield::select()
{
	OneSheeld.sendPacket(PROXIMITY_ID,0,PROXIMITY_SELECT_SHIELD,0);
}

void ProximitySensorShield::unselect()
{
	OneSheeld.sendPacket(PROXIMITY_ID,0,PROXIMITY_UNSELECT_SHIELD,0);
}

//ProximitySensor Input Data Processing 
void ProximitySensorShield::processData()
{
	//Checking Function-ID
	byte functionId =OneSheeld.getFunctionId();
	if(functionId==PROXIMITY_VALUE)
	{
		value=OneSheeld.getArgumentData(0)[0];
		//Users Function Invoked
		if (isCallBackAssigned)
		(*changeCallBack)(value);
	}
	else if(functionId==PROXIMITY_CHECK_SELECTED)
	{
		(*selectedCallBack)();
	}
}
//Users Function Setter
void ProximitySensorShield::setOnValueChange(void (*userFunction)(byte proximityValue))
{
	changeCallBack=userFunction;
	isCallBackAssigned=true;
}

void ProximitySensorShield::setOnSelected(void (*userFunction)(void))
{
	selectedCallBack=userFunction;
}

//Instatntiating Object
ProximitySensorShield ProximitySensor;
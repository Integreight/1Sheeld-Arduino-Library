/*

  Project:       1Sheeld Library 
  File:          ToggleButtonShield.cpp
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/

#include "OneSheeld.h"
#include "ToggleButtonShield.h"


//Class Constructor
ToggleButtonShield::ToggleButtonShield()
{
	value=0x00;
	isCallBackAssigned=false;
}
//ToggleButton Checker
bool ToggleButtonShield::getStatus()
{
	return !!value;
}

void ToggleButtonShield::select()
{
	OneSheeld.sendPacket(TOGGLE_BUTTON_ID,0,TOGGLEBUTTON_SELECT_SHIELD,0);
}

void ToggleButtonShield::unselect()
{
	OneSheeld.sendPacket(TOGGLE_BUTTON_ID,0,TOGGLEBUTTON_UNSELECT_SHIELD,0);
}
//ToggleButton Input Data Processing
void ToggleButtonShield::processData()
{
	//Checking Function-ID
	byte functionId= OneSheeld.getFunctionId();
	if(functionId==TOGGLEBUTTON_VALUE)
	{
		value=OneSheeld.getArgumentData(0)[0];
		//Users Function Invoked
		if(isCallBackAssigned)
			(*changeCallBack)(!!value);
	}
	else if(functionId == TOGGLEBUTTON_CHECK_SELECTED)
	{
		(*selectedCallBack)();
	}
}
//Users Function Setter
void ToggleButtonShield::setOnButtonStatusChange(void (*userFunction)(bool toggleButtonValue))
{
	changeCallBack=userFunction;
	isCallBackAssigned=true;
}

void ToggleButtonShield::setOnSelected(void (*userFunction)(void))
{
	selectedCallBack=userFunction;
}
//Instantiating Object
ToggleButtonShield ToggleButton;
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
//ToggleButton Input Data Processing
void ToggleButtonShield::processData()
{
	//Checking Function-ID
	byte functionId= OneSheeld.getFunctionId();
	if(functionId==TOGGLE_VALUE)
	{
		value=OneSheeld.getArgumentData(0)[0];
		//Users Function Invoked
		if(isCallBackAssigned)
			(*changeCallBack)(!!value);
	}
}
//Users Function Setter
void ToggleButtonShield::setOnButtonStatusChange(void (*userFunction)(bool toggleButtonValue))
{
	changeCallBack=userFunction;
	isCallBackAssigned=true;
}

//Instantiating Object
ToggleButtonShield ToggleButton;
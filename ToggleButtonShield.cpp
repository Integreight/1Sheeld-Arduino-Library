/*

  Project:       1Sheeld Library 
  File:          ToggleButtonShield.cpp
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/
#define FROM_ONESHEELD_LIBRARY
#include "OneSheeld.h"
#include "ToggleButtonShield.h"


//Class Constructor
ToggleButtonShield::ToggleButtonShield() : ShieldParent(TOGGLE_BUTTON_ID)
{
	value=0;
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
	byte functionId= getOneSheeldInstance().getFunctionId();
	if(functionId==TOGGLEBUTTON_VALUE)
	{
		value=getOneSheeldInstance().getArgumentData(0)[0];
		//Users Function Invoked
		if(isCallBackAssigned && !isInACallback())
		{
			enteringACallback();
			(*changeCallBack)(!!value);
			exitingACallback();
		}
	}
}
//Users Function Setter
void ToggleButtonShield::setOnButtonStatusChange(void (*userFunction)(bool toggleButtonValue))
{
	changeCallBack=userFunction;
	isCallBackAssigned=true;
}


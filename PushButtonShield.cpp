/*

  Project:       1Sheeld Library 
  File:          PushButtonShield.cpp
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/
#define FROM_ONESHEELD_LIBRARY
#include "OneSheeld.h"
#include "PushButtonShield.h"

//Class Constructor
PushButtonShield::PushButtonShield() : ShieldParent(PUSH_BUTTON_ID)
{
	value=0;
	isCallBackAssigned=false;
}
//PushButton Checker 
bool PushButtonShield::isPressed()
{
	return !!value;
}

//Phone Input Data Processing 
void PushButtonShield::processData()
{
	//Checking Function-ID
	byte functionId =getOneSheeldInstance().getFunctionId();
	if(functionId==PUSHBUTTON_VALUE)
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
void PushButtonShield::setOnButtonStatusChange(void (*userFunction)(bool pushButtonValue))
{
	changeCallBack=userFunction;
	isCallBackAssigned=true;
}


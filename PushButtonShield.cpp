/*

  Project:       1Sheeld Library 
  File:          PushButtonShield.cpp
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/

#include "OneSheeld.h"
#include "PushButtonShield.h"



//Class Constructor
PushButtonShield::PushButtonShield()
{
	value=0x00;
	isCallBackAssigned=false;
}
//PushButton Checker 
bool PushButtonShield::isPressed()
{
	return !!value;
}

void PushButtonShield::select()
{
	OneSheeld.sendPacket(PUSH_BUTTON_ID,0,PUSHBUTTON_SELECT_SHIELD,0);
}

void PushButtonShield::unselect()
{
	OneSheeld.sendPacket(PUSH_BUTTON_ID,0,PUSHBUTTON_UNSELECT_SHIELD,0);
}

//Phone Input Data Processing 
void PushButtonShield::processData()
{
	//Checking Function-ID
	byte functionId =OneSheeld.getFunctionId();

	if(functionId==PUSHBUTTON_VALUE)
	{
		value=OneSheeld.getArgumentData(0)[0];
		//Users Function Invoked
		if(isCallBackAssigned)
			(*changeCallBack)(!!value);
	}
	else if(functionId == PUSHBUTTON_CHECK_SELECTED)
	{
		(*selectedCallBack)();
	}
}
//Users Function Setter
void PushButtonShield::setOnButtonStatusChange(void (*userFunction)(bool pushButtonValue))
{
	changeCallBack=userFunction;
	isCallBackAssigned=true;
}

void PushButtonShield::setOnSelected(void (*userFunction)(void))
{
	selectedCallBack=userFunction;
}

//Instatntiating Object
PushButtonShield PushButton;
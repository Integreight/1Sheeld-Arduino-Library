/*

  Project:       1Sheeld Library 
  File:          GamePadShield.cpp
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/
#define FROM_ONESHEELD_LIBRARY
#include "OneSheeld.h"
#include "GamePadShield.h"



//Class Constructor
GamePadShield::GamePadShield() : ShieldParent(GAMEPAD_ID)
{
	value =0;
	isCallBackAssigned=false;
}

//Up ArrowChecker
bool GamePadShield::isUpPressed()
{
	return !!(value & (1<<UP_BIT));
}
//Down Arrow Checker 
bool GamePadShield::isDownPressed()
{
	return !!(value & (1<<DOWN_BIT));
}
//Left Arrow Checker
bool GamePadShield::isLeftPressed()
{	
	return  !!(value & (1<<LEFT_BIT));
}
//Right Arrow Checker
bool GamePadShield::isRightPressed()
{
	return !!(value & (1<<RIGHT_BIT));
}
//Orange Button Checker
bool GamePadShield::isOrangePressed()
{
	return !!(value & (1<<ORANGE_BIT));
}
//Red Button Checker 
bool GamePadShield::isRedPressed()
{
	return !!(value & (1<<RED_BIT));
}
//Green Button Checker 
bool GamePadShield::isGreenPressed()
{
	return !!(value & (1<<GREEN_BIT));
}
//Blue Button Checker
bool GamePadShield::isBluePressed()
{
	return !!(value & (1<<BLUE_BIT));
}

//GamePad Input Data Processing  
void GamePadShield::processData()
{
	//Checking Function-ID
	byte functionId =getOneSheeldInstance().getFunctionId();
	if(functionId==GAMEPAD_VALUE)
	{
		value=getOneSheeldInstance().getArgumentData(0)[0];
		//Users Function Invoked
		if(isCallBackAssigned && !isInACallback())
		{
			enteringACallback();
			(*buttonChangeCallBack)(!!(value & (1<<UP_BIT)),      !!(value & (1<<DOWN_BIT)),
									!!(value & (1<<LEFT_BIT)), 	  !!(value & (1<<RIGHT_BIT)),
									!!(value & (1<<ORANGE_BIT)),  !!(value & (1<<RED_BIT)), 
									!!(value & (1<<GREEN_BIT)),   !!(value & (1<<BLUE_BIT)));
			exitingACallback();
		}
	}
}

//Users Function Setter 
void GamePadShield::setOnButtonChange(void (* userFunction)(unsigned char up,unsigned char down,unsigned char left,unsigned char right,unsigned char orange ,unsigned char red,unsigned char green,unsigned char blue))
{
	buttonChangeCallBack=userFunction;
	isCallBackAssigned=true;
}


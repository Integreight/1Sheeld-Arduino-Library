/*

  Project:       1Sheeld Library 
  File:          KeyboardShield.cpp
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/
#define FROM_ONESHEELD_LIBRARY
#include "OneSheeld.h"
#include "KeyboardShield.h"

//Class Constructor
 KeyboardShield::KeyboardShield() : ShieldParent(KEYBOARD_ID)
{
	character=0;
	isCallBackAssigned=false;
}

//Getter 
char KeyboardShield::getCharacter()
{
	return character;
}

//Keyboard Input Data Processing 
void KeyboardShield::processData()
{
	//Checking Function-ID
	byte functionId=getOneSheeldInstance().getFunctionId();
	if (functionId==KEYBOARD_GET_CHAR)
	{
		
		character=getOneSheeldInstance().getArgumentData(0)[0];
		//Users Function Invoked
		if(isCallBackAssigned && !isInACallback())
		{
			enteringACallback();
			(*buttonChangeCallBack)(character);
			exitingACallback();
		}
	}
}
//Users Function Setter
void KeyboardShield::setOnButtonChange(void (*userFunction)(char data))
{
	buttonChangeCallBack=userFunction;
	isCallBackAssigned=true;
}


/*

  Project:       1Sheeld Library 
  File:          KeyboardShield.cpp
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/

#include "OneSheeld.h"
#include "KeyboardShield.h"

//Class Constructor
 KeyboardShield::KeyboardShield()
{
	character=NULL;
	isCallBackAssigned=false;
}

//Getter 
char KeyboardShield::getCharacter()
{
	return character;
}

void KeyboardShield::select()
{
	OneSheeld.sendPacket(KEYBOARD_ID,0,KEYBPARD_SELECT_SHIELD,0);
}

void KeyboardShield::unselect()
{
	OneSheeld.sendPacket(KEYBOARD_ID,0,KEYBPARD_UNSELECT_SHIELD,0);
}
//Keyboard Input Data Processing 
void KeyboardShield::processData()
{
	//Checking Function-ID
	byte functionId=OneSheeld.getFunctionId();
	if (functionId==KEYBOARD_GET_CHAR)
	{
		
		character=OneSheeld.getArgumentData(0)[0];
		//Users Function Invoked
		if(isCallBackAssigned)
		{
			(*buttonChangeCallBack)(character);
		}
	}
	else if(functionId == KEYBOARD_CHECK_SELECTED)
	{
		(*selectedCallBack)();
	}
}
//Users Function Setter
void KeyboardShield::setOnButtonChange(void (*userFunction)(char data))
{
	buttonChangeCallBack=userFunction;
	isCallBackAssigned=true;
}

void KeyboardShield::setOnSelected(void (*userFunction)())
{
	selectedCallBack=userFunction;
}

/*Instantiate object to user*/
KeyboardShield AsciiKeyboard;
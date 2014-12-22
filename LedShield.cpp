/*

  Project:       1Sheeld Library 
  File:          LEDShield.cpp
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/

#include "OneSheeld.h"
#include "LedShield.h"

//LedOff Setter
void LedShield::setLow()
{
	setValue(LED_SET_LOW);
}
//LedOn Setter
void LedShield::setHigh()
{
	setValue(LED_SET_HIGH);
}
//Setter 
void LedShield::setValue(byte data)
{
	OneSheeld.sendPacket(LED_ID,0,LED_SET_VALUE,1,new FunctionArg(1,&data));
}

void LedShield::select()
{
	OneSheeld.sendPacket(LED_ID,0,LED_SELECT_SHIELD,0);
}

void LedShield::unselect()
{
	OneSheeld.sendPacket(LED_ID,0,LED_UNSELECT_SHIELD,0);
}

void LedShield::processData()
{
	byte functionId = OneSheeld.getFunctionId();

	if(functionId == LED_CHECK_SELECTED)
	{
		(*selectedCallBack)();
	}
}

void LedShield::setOnSelected(void (*userFunction)(void))
{
	selectedCallBack=userFunction;
}
//Instantiating Object
LedShield LED;
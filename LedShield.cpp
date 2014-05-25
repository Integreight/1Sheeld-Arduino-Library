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

//Setter
void LedShield::setLow()
{
	setValue(SET_LOW);
}
//Setter
void LedShield::setHigh()
{
	setValue(SET_HIGH);
}
//Setter 
void LedShield::setValue(byte data)
{
	OneSheeld.sendPacket(LED_ID,0,SET_VALUE,1,new FunctionArg(1,&data));
}

//Instantiating Object
LedShield LED;
/*

  Project:       1Sheeld Library 
  File:          LEDShield.cpp
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/
#define FROM_ONESHEELD_LIBRARY
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
	OneSheeld.sendShieldFrame(LED_ID,0,LED_SET_VALUE,1,new FunctionArg(1,&data));
}


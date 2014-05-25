/*

  Project:       1Sheeld Library 
  File:          BuzzerShield.cpp
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/
  
#include "OneSheeld.h"
#include "BuzzerShield.h"

//Class Constructor
BuzzerShieldClass::BuzzerShieldClass()
{
	buzzing = false;
}

//Buzzing On 
void BuzzerShieldClass::buzzOn()
{
	if(buzzing == false)
	{
		setValue(BUZZ_ON);
		buzzing=true;
	}
	
}

//Buzzing Off 
void BuzzerShieldClass::buzzOff()
{
	if(buzzing == true)
	{
		setValue(BUZZ_OFF);
		buzzing=false;
	}
	
}

//Buzz Setter 
void BuzzerShieldClass::setValue(byte x)
{
	OneSheeld.sendPacket(BUZZER_ID,0,SET_VALUE,1,new FunctionArg(1,&x));
}

//instantiating Object
BuzzerShieldClass Buzzer;
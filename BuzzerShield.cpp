/*

  Project:       1Sheeld Library 
  File:          BuzzerShield.cpp
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/
#define FROM_ONESHEELD_LIBRARY
#include "OneSheeld.h"
#include "BuzzerShield.h"

//Class Constructor
BuzzerShieldClass::BuzzerShieldClass():ShieldParent(BUZZER_ID)
{
	buzzing = false;
}

//Buzzing On 
void BuzzerShieldClass::buzzOn()
{
	if(buzzing == false)
	{
		setValue(BUZZER_ON);
		buzzing=true;
	}
	
}

//Buzzing Off 
void BuzzerShieldClass::buzzOff()
{
	if(buzzing == true)
	{
		setValue(BUZZER_OFF);
		buzzing=false;
	}
	
}

//Buzz Setter 
void BuzzerShieldClass::setValue(byte x)
{
	OneSheeld.sendShieldFrame(BUZZER_ID,0,BUZZER_SET,1,new FunctionArg(1,&x));
}


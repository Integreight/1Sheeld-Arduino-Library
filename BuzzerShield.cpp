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
	OneSheeld.sendPacket(BUZZER_ID,0,BUZZER_SET,1,new FunctionArg(1,&x));
}

void BuzzerShieldClass::select()
{
	OneSheeld.sendPacket(BUZZER_ID,0,BUZZER_SELECT_SHIELD,0);
}

void BuzzerShieldClass::unselect()
{
	OneSheeld.sendPacket(BUZZER_ID,0,BUZZER_UNSELECT_SHIELD,0);
}

void BuzzerShieldClass::processData()
{
	byte functionId = OneSheeld.getFunctionId();

	if(functionId == BUZZER_CHECK_SELECTED)
	{
		(*selectedCallBack)();
	}
}

void BuzzerShieldClass::setOnSelected(void (*userFunction)(void))
{
	selectedCallBack=userFunction;
}


//instantiating Object
BuzzerShieldClass Buzzer;
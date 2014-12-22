/*

  Project:       1Sheeld Library 
  File:          SliderShield.cpp
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/

#include "OneSheeld.h"
#include "SliderShield.h"

//Class Constructor
SliderShield::SliderShield()
{
	value=0x00;
	isCallBackAssigned=false;
}
//Slider Getter
byte SliderShield::getValue()
{
	return value;
}

void SliderShield::select()
{
	OneSheeld.sendPacket(SLIDER_ID,0,SLIDER_SELECT_SHIELD,0);
}

void SliderShield::unselect()
{
	OneSheeld.sendPacket(SLIDER_ID,0,SLIDER_UNSELECT_SHIELD,0);
}
//Phone Input Data Processing 
void SliderShield::processData()
{
	//Checking Function-ID
	byte functionId= OneSheeld.getFunctionId();

	if(functionId==SLIDER_VALUE)
		{
			value= OneSheeld.getArgumentData(0)[0];
			//Users Function Invoked
			if(isCallBackAssigned)
				(*changeCallBack)(value);
		}
		else if(functionId == SLIDER_CHECK_SELECTED)
		{
			(*selectedCallBack)();
		}
}
//Users Function Setter
void SliderShield::setOnValueChange(void (*userFunction)(byte sliderValue))
{
	changeCallBack=userFunction;
	isCallBackAssigned=true;
}

void SliderShield::setOnSelected(void (*userFunction)(void))
{
	selectedCallBack=userFunction;
}

//Instatntiating Object
SliderShield Slider;
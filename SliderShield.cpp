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
}
//Users Function Setter
void SliderShield::setOnValueChange(void (*userFunction)(byte sliderValue))
{
	changeCallBack=userFunction;
	isCallBackAssigned=true;
}

//Instatntiating Object
SliderShield Slider;
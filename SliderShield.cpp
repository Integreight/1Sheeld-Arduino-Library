/*

  Project:       1Sheeld Library 
  File:          SliderShield.cpp
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/
#define FROM_ONESHEELD_LIBRARY
#include "OneSheeld.h"
#include "SliderShield.h"

//Class Constructor
SliderShield::SliderShield() : ShieldParent(SLIDER_ID)
{
	value=0;
	isCallBackAssigned=false;
}
//Slider Getter
byte SliderShield::getValue()
{
	return value;
}

void SliderShield::setValue(int value)
{
	byte copiedValue ;
	if(value>255) 
	{
		copiedValue= 255;
	}
	else if (value < 0)
	{
		copiedValue= 0;
	}
	else
	{
		copiedValue = value;
	}
	OneSheeld.sendShieldFrame(SLIDER_ID,0,SLIDER_SET,1,new FunctionArg(1,&copiedValue));
}

//Phone Input Data Processing 
void SliderShield::processData()
{
	//Checking Function-ID
	byte functionId= getOneSheeldInstance().getFunctionId();

	if(functionId==SLIDER_VALUE)
		{
			value= getOneSheeldInstance().getArgumentData(0)[0];
			//Users Function Invoked
			if(isCallBackAssigned && !isInACallback())
			{
				enteringACallback();
				(*changeCallBack)(value);
				exitingACallback();
			}
		}
}
//Users Function Setter
void SliderShield::setOnValueChange(void (*userFunction)(byte sliderValue))
{
	changeCallBack=userFunction;
	isCallBackAssigned=true;
}


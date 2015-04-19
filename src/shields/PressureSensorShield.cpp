/*

  Project:       1Sheeld Library 
  File:          PressureSensorShield.cpp
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/
#define FROM_ONESHEELD_LIBRARY
#include "OneSheeld.h"
#include "PressureSensorShield.h"

//Class Constructor
PressureSensorShield::PressureSensorShield() : ShieldParent(PRESSURE_ID)
{
	value=0;
	isCallBackAssigned=false;
}
//Pressure Getter
int PressureSensorShield::getValue()
{
	
	return value;
	
}

//PressureSensor Input Data Processing 
void PressureSensorShield::processData()
{
	//Checking Function-ID
	byte functionId =getOneSheeldInstance().getFunctionId();
	if(functionId==PRESSURE_VALUE)
	{
		value=(getOneSheeldInstance().getArgumentData(0)[1]<<8)|(getOneSheeldInstance().getArgumentData(0)[0]);
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
void PressureSensorShield::setOnValueChange(void (*userFunction)(unsigned long pressureValue))
{
	changeCallBack=userFunction;
	isCallBackAssigned=true;
}


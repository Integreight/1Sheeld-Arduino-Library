/*

  Project:       1Sheeld Library 
  File:          LightSensorShield.cpp
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/
#include "OneSheeld.h"
#include "LightSensorShield.h"

//Class Constructor
LightSensorShield::LightSensorShield() : ShieldParent(LIGHT_ID)
{
	value=0;
	isCallBackAssigned=false;
}
//Light Getter 
unsigned long LightSensorShield::getValue()
{
	
	return value;
	
}
//Light Input Data Processing
void LightSensorShield::processData()
{
	//Checking Function-ID
	byte functionId =getOneSheeldInstance().getFunctionId();
	if(functionId==LIGHT_VALUE)
	{
		value = getOneSheeldInstance().convertBytesToFloat(getOneSheeldInstance().getArgumentData(0));
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
void LightSensorShield::setOnValueChange(void (*userFunction)(unsigned long lightValue))
{
	changeCallBack=userFunction;
	isCallBackAssigned=true;
}

#ifdef LIGHT_SHIELD
//Instantiating Object
LightSensorShield LightSensor;
#endif
/*

  Project:       1Sheeld Library 
  File:          MicShield.cpp
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/
#include "OneSheeld.h"
#include "MicShield.h"


//Class Constructor
MicShield::MicShield():ShieldParent(MIC_ID)
{
	value=0x00;
	isCallBackAssigned=false;
}
//Mic Getter
byte MicShield::getValue()
{
	return value;
}

//Mic Input Data processing 	
void MicShield::processData()
{
	//Checking Function-ID
	byte functionId =getOneSheeldInstance().getFunctionId();
	if(functionId==MIC_VALUE)
	{
		value=0;
		value=getOneSheeldInstance().getArgumentData(0)[0];

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
void MicShield::setOnValueChange(void (*userFunction)(byte micValue))
{
	changeCallBack=userFunction;
	isCallBackAssigned=true;
}

#ifdef MIC_SHIELD
//Instatntiating Object
MicShield Mic;
#endif
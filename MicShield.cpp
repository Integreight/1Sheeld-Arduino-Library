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
MicShield::MicShield()
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
	byte functionId =OneSheeld.getFunctionId();
	if(functionId==MIC_VALUE)
	{
		value=0;
		value=OneSheeld.getArgumentData(0)[0];

		//Users Function Invoked
		if(isCallBackAssigned)
			(*changeCallBack)(value);
	}
}

//Users Function Setter 
void MicShield::setOnValueChange(void (*userFunction)(byte micValue))
{
	changeCallBack=userFunction;
	isCallBackAssigned=true;
}

//Instatntiating Object
MicShield Mic;
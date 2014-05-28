/*

  Project:       1Sheeld Library 
  File:          PhoneShield.cpp
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/

#include "OneSheeld.h"
#include "PhoneShield.h"

//Class Constructor
PhoneShieldClass::PhoneShieldClass()
{
	value=0;
	number=0;
	isCallBackAssigned=false;	
}
//Call Setter 
void PhoneShieldClass::call(char* phone)
{
	OneSheeld.sendPacket(PHONE_ID,0,CALL_PHONE,1,new FunctionArg(strlen(phone),(byte *)phone));
}
//Ringing Checker 
bool PhoneShieldClass::isRinging()
{
	return !!value;
}
//Number Getter
char * PhoneShieldClass::getNumber()
{
	return number;
}
//Phone Input Data Processing 
void PhoneShieldClass::processData()
{	
	//Checking Function-ID
	byte x= OneSheeld.getFunctionId();

	if (x==IS_RINGING_VALUE)
	{
		value =OneSheeld.getArgumentData(0)[0];
	}
	else if (x==GET_NUMBER_VALUE)
	{
		if(number!=0)
		{
			free(number);
		}
		
		byte length=OneSheeld.getArgumentLength(0);
		
		number=(char*)malloc(sizeof(char)*(length+1));
		
		for (int i=0; i< length;i++)
			{
				number[i]=OneSheeld.getArgumentData(0)[i];
			}

			number[length]='\0';
			//Users Function Invoked
			if (isCallBackAssigned)
			{
				(*changeCallBack)(value,number);
			}
	}
	


}

//Users Function Setter
void PhoneShieldClass::setOnCallStatusChange(void (*userFunction)(bool isRinging, char * phoneNumber))
{
	changeCallBack=userFunction;
	isCallBackAssigned=true;
}


//Instatntiating Object
PhoneShieldClass Phone;

/*
  SMSShield.h - SMSShield library
  Copyright (C) 2013 Integreight Inc  All rights reserved.
*/
#include "OneSheeld.h"
#include "PhoneShield.h"

// public function

PhoneShieldClass::PhoneShieldClass()
{
	value=0;
	number=0;
	isCallBackAssigned=false;	
}
void PhoneShieldClass::call(char* phone)
{
	OneSheeld.sendPacket(PHONE_ID,0,CALL_PHONE,1,new FunctionArg(strlen(phone),(byte *)phone));
}

void PhoneShieldClass::processData()
{
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
	}
	if (isCallBackAssigned)
	{
		(*changeCallBack)(value,number);
	}


}

void PhoneShieldClass::setOnChange(void (*userFunction)(bool isRinging, char * phoneNumber))
{
	changeCallBack=userFunction;
	isCallBackAssigned=true;
}

bool PhoneShieldClass::isRinging()
{
	return !!value;
}

char * PhoneShieldClass::getNumber()
{
	return number;
}

// instantiate object for users
PhoneShieldClass Phone;

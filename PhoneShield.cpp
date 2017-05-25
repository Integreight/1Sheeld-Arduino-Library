/*

  Project:       1Sheeld Library 
  File:          PhoneShield.cpp
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/
#define FROM_ONESHEELD_LIBRARY
#include "OneSheeld.h"
#include "PhoneShield.h"

//Class Constructor
PhoneShieldClass::PhoneShieldClass() : ShieldParent(PHONE_ID)
{
	value=0;
	number=NULL;
	isCallBackAssigned=false;
	usedSetOnString=false;	
}
//Call Setter 
void PhoneShieldClass::call(const char* phone)
{
	//Check length of string 
	int phoneLength = strlen(phone);
	if(!phoneLength) return;
	OneSheeld.sendShieldFrame(PHONE_ID,0,PHONE_CALL,1,new FunctionArg(phoneLength,(byte *)phone));
}

void PhoneShieldClass::call(String phone)
{
	call(&phone[0]);
}

//Ringing Checker 
bool PhoneShieldClass::isRinging()
{
	return !!value;
}
//Number Getter
char * PhoneShieldClass::getNumber()
{
	value=!!value;
	return number;
}

String PhoneShieldClass::getNumberAsString()
{
	String phoneNumberAsString(number);
	return phoneNumberAsString;
}

//Phone Input Data Processing 
void PhoneShieldClass::processData()
{
	//Checking Function-ID
	byte functionId= getOneSheeldInstance().getFunctionId();

	if (functionId==PHONE_IS_RINGING)
	{
		value =getOneSheeldInstance().getArgumentData(0)[0];
	}
	else if (functionId==PHONE_GET_NUMBER)
	{
		if(number!=0)
		{
			free(number);
		}
		
		byte length=getOneSheeldInstance().getArgumentLength(0);
		
		number=(char*)malloc(sizeof(char)*(length+1));
		
		for (int i=0; i< length;i++)
			{
				number[i]=getOneSheeldInstance().getArgumentData(0)[i];
			}

			number[length]='\0';
			//Users Function Invoked
			if(!isInACallback())
			{
				if (isCallBackAssigned)
				{
					enteringACallback();
					(*changeCallBack)(value,number);
					exitingACallback();
				}
				if(usedSetOnString)
				{
					enteringACallback();
					String phoneNumberAsString(number);
					(*changeCallBackString)(value,phoneNumberAsString);
					exitingACallback();
				}
			}
	}
}

//Users Function Setter
void PhoneShieldClass::setOnCallStatusChange(void (*userFunction)(bool isRinging,char  phoneNumber []))
{
	changeCallBack=userFunction;
	isCallBackAssigned=true;
}

void PhoneShieldClass::setOnCallStatusChange(void (*userFunction)(bool isRinging,String phoneNumber))
{
	changeCallBackString=userFunction;
	usedSetOnString=true;
}


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
	OneSheeld.sendPacket(PHONE_ID,0,PHONE_CALL,1,new FunctionArg(strlen(phone),(byte *)phone));
}

//Support string for Arduino
#if !defined(ARDUINO_LINUX)
void PhoneShieldClass::call(String phone)
{
	const char * cTypePhone = phone.c_str();

	call(cTypePhone);
}
#endif

//Support string for galileo
#if defined(ARDUINO_LINUX)
void PhoneShieldClass::call(String phone)
{
	int phoneLength = phone.length();

	char cTypePhone[phoneLength+1];

	for(int i=0; i<phoneLength ;i++)
	{
		cTypePhone[i]=phone[i];
	}
	cTypePhone[phoneLength]='\0';

	call(cTypePhone);
}
#endif
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
	byte functionId= OneSheeld.getFunctionId();

	if (functionId==PHONE_IS_RINGING)
	{
		value =OneSheeld.getArgumentData(0)[0];
	}
	else if (functionId==PHONE_GET_NUMBER)
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
void PhoneShieldClass::setOnCallStatusChange(void (*userFunction)(bool isRinging,char * phoneNumber))
{
	changeCallBack=userFunction;
	isCallBackAssigned=true;
}

void PhoneShieldClass::setOnCallStatusChange(void (*userFunction)(bool isRinging,String phoneNumber))
{
	changeCallBackString=userFunction;
	usedSetOnString=true;
}

#ifdef PHONE_SHIELD
//Instatntiating Object
PhoneShieldClass Phone;
#endif

/*
  SMSShield.h - SMSShield library
  Copyright (C) 2013 Integreight Inc  All rights reserved.
*/

#include "OneSheeld.h"
#include "PhoneShield.h"

// public functions
PhoneShieldClass::PhoneShieldClass(){}
void PhoneShieldClass::call(char* phone)
{
	char str[140];
	strcpy (str, "");
	strcat (str, phone);
	OneSheeld.sendPacket(PHONE_ID,0,CALL_PHONE,1,new FunctionArg(strlen(str),(byte *)str));
}

// instantiate object for users
PhoneShieldClass Phone;
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
	OneSheeld.write(PHONE_ID,CALL_PHONE,str);
}

// instantiate object for users
PhoneShieldClass Phone;
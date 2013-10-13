/*
  SMSShield.h - SMSShield library
  Copyright (C) 2013 Integreight Inc  All rights reserved.
*/

#include "OneSheeld.h"
#include "SMSShield.h"

// public functions
SMSShieldClass::SMSShieldClass(){}
void SMSShieldClass::send(char* number,char* text)
{
	char str[140];
	strcpy (str, "");
	strcat (str, number);
	strcat (str, "##");
	strcat (str, text);
	OneSheeld.write(SMS_ID,SEND_SMS,str);
}

// instantiate object for users
SMSShieldClass SMS;
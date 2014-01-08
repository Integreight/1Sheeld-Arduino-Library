/*
  SMSShield.h - SMSShield library
  Copyright (C) 2013 Integreight Inc  All rights reserved.
*/

#include "OneSheeld.h"
#include "EmailShield.h"

// public functions
EmailShieldClass::EmailShieldClass(){}
void EmailShieldClass::send(char* email,char* msg)
{
	char str[140];
	strcpy (str, "");
	strcat (str, email);
	strcat (str, "##");
	strcat (str, msg);
	OneSheeld.write(EMAIL_ID,SEND_SMS,str);
}

// instantiate object for users
EmailShieldClass Email;
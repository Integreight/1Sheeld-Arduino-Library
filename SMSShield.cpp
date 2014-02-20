/*
  SMSShield.h - SMSShield library
  Copyright (C) 2013 Integreight Inc  All rights reserved.
*/
#include "OneSheeld.h"
#include "SMSShield.h"

// public functions
void SMSShieldClass::send(char* number,char* text)
{
	OneSheeld.sendPacket(SMS_ID,0,SEND_SMS,2,new FunctionArg(strlen(number),(byte*)number),new FunctionArg(strlen(text),(byte*)text));
}

// instantiate object for users
SMSShieldClass SMS;
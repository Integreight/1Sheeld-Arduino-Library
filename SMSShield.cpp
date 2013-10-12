/*
  SMSShield.h - SMSShield library
  Copyright (C) 2013 Integreight Inc  All rights reserved.
*/

#include "OneSheeld.h"
#include "SMSShield.h"

// public functions
SMSShieldClass::SMSShieldClass(){}
void send(char* number,char* text)
{
OneSheeld.write(SMS_ID,SEND_SMS,text);
}

// instantiate object for users
SMSShieldClass SMS;
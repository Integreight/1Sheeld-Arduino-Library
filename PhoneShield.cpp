/*
  SMSShield.h - SMSShield library
  Copyright (C) 2013 Integreight Inc  All rights reserved.
*/
#include "OneSheeld.h"
#include "PhoneShield.h"
// public function
void PhoneShieldClass::call(char* phone)
{
	OneSheeld.sendPacket(PHONE_ID,0,CALL_PHONE,1,new FunctionArg(strlen(phone),(byte *)phone));
}

// instantiate object for users
PhoneShieldClass Phone;
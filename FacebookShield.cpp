/*
  FacebookShield.h - FacebookShield library
  Copyright (C) 2013 Integreight Inc  All rights reserved.
*/

#include "OneSheeld.h"
#include "FacebookShield.h"

// public functions
FacebookShieldClass::FacebookShieldClass(){}
void FacebookShieldClass::updateStatus(char* status)
{
OneSheeld.sendPacket(FACEBOOK_ID,0,UPDATE_STATUS,1,new FunctionArg(strlen(status),(byte*)status));
}

// instantiate object for users
FacebookShieldClass Facebook;
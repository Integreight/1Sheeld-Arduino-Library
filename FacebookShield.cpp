/*
  FacebookShield.h - FacebookShield library
  Copyright (C) 2013 Integreight Inc  All rights reserved.
*/

#include "OneSheeld.h"
#include "FacebookShield.h"

// public functions
FacebookShieldClass::FacebookShieldClass(){}
void FacebookShieldClass::updateStatus(char* data)
{
OneSheeld.write(FACEBOOK_ID,UPDATE_STATUS,data);
}

// instantiate object for users
FacebookShieldClass Facebook;
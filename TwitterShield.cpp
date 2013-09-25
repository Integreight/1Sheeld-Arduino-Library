/*
  TwitterShield.h - TwitterShield library
  Copyright (C) 2013 Integreight Inc  All rights reserved.
*/

#include "OneSheeld.h"
#include "TwitterShield.h"

// public functions
TwitterShieldClass::TwitterShieldClass(){}
void TwitterShieldClass::updateStatus(char* data)
{
OneSheeld.write(TWITTER_ID,SEND_TWEET,data);
}

// instantiate object for users
TwitterShieldClass Twitter;
/*
  TwitterShield.h - TwitterShield library
  Copyright (C) 2013 Integreight Inc  All rights reserved.
*/

#include "OneSheeld.h"
#include "TwitterShield.h"

// public functions
void TwitterShieldClass::updateStatus( char *data)
{
OneSheeld.sendPacket(TWITTER_ID,0,SEND_TWEET,1,new FunctionArg(strlen(data),(byte*)data));
}
void TwitterShieldClass::sendDirectMessage(char* username,char* message)
{

	OneSheeld.sendPacket(TWITTER_ID,0,SEND_DIRECT_MESSAGE,2,new FunctionArg(strlen(username),(byte*)username),new FunctionArg(strlen(message),(byte*) message));

}
// instantiate object for users
TwitterShieldClass Twitter;
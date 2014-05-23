/*
  FacebookShield.h - FacebookShield library
  Copyright (C) 2013 Integreight Inc  All rights reserved.
*/

#include "OneSheeld.h"
#include "FacebookShield.h"

// public functions
void FacebookShieldClass::post(char* status)
{
	OneSheeld.sendPacket(FACEBOOK_ID,0,UPDATE_STATUS,1,new FunctionArg(strlen(status),(byte*)status));
}

void FacebookShieldClass::sendMessage(char * username,char * message)
{
	OneSheeld.sendPacket(FACEBOOK_ID,0,SEND_MESSAGE,2,new FunctionArg (strlen(username),(byte*)username),new FunctionArg(strlen(message),(byte*)message)); 
}

// instantiate object for users
FacebookShieldClass Facebook;
/*
  TwitterShield.h - TwitterShield library
  Copyright (C) 2013 Integreight Inc  All rights reserved.
*/

#include "OneSheeld.h"
#include "TwitterShield.h"


// public functions
TwitterShieldClass::TwitterShieldClass(){}
void TwitterShieldClass::updateStatus( char *data)
{
OneSheeld.sendPacket(TWITTER_ID,0,SEND_TWEET,1,new FunctionArg(strlen(data),(byte*)data));
}
void TwitterShieldClass::sendDirectMessage(char* username,char* message)
{
int length = strlen(username)+ strlen(message);
char data[length];
for (int i=0;i<( strlen(username));i++)
{
data[i]=username[i];
}

data[ strlen(username)]=0xff;
for (int i=0;i<=strlen(message);i++)
{
data[i+strlen(username)+1]=message[i];
}
OneSheeld.sendPacket(TWITTER_ID,0,SEND_DIRECT_MESSAGE,2,new FunctionArg(strlen(username),(byte*)username),new FunctionArg(strlen(message),(byte*) message));

}
// instantiate object for users
TwitterShieldClass Twitter;
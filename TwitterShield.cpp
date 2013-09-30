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
void TwitterShieldClass::sendDirectMessage(char* username,char* message)
{
int length = sizeof(username)+sizeof(message);
char data[length];
for (int i=0;i<(sizeof(username));i++)
{
data[i]=username[i];
}
data[sizeof(username)]=0xff;
for (int i=0;i<sizeof(message);i++)
{
data[i+sizeof(username)+1]=message[i];
}
OneSheeld.write(TWITTER_ID,SEND_DIRECT_MESSAGE,data);

}
// instantiate object for users
TwitterShieldClass Twitter;
/*
  SMSShield.h - SMSShield library
  Copyright (C) 2013 Integreight Inc  All rights reserved.
*/
#ifndef EmailShield_h
#define EmailShield_h

// library defintions
#define SEND_EMAIL 0x01  // sendTweet function command

class EmailShieldClass 
{
public:
EmailShieldClass();
void send(char* email,char* msg);

private:



};
// instantiate object for users
extern EmailShieldClass Email;
#endif
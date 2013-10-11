/*
  FacebookShield.h - FacebookShield library
  Copyright (C) 2013 Integreight Inc  All rights reserved.
*/
#ifndef FacebookShield_h
#define FacebookShield_h

// library defintions
#define UPDATE_STATUS 0x01  // sendTweet function command

class FacebookShieldClass 
{
public:
FacebookShieldClass();
void updateStatus(char* data);

private:



};
// instantiate object for users
extern FacebookShieldClass Facebook;
#endif
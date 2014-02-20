/*
  SMSShield.h - SMSShield library
  Copyright (C) 2013 Integreight Inc  All rights reserved.
*/
#ifndef PhoneShield_h
#define PhoneShield_h

// library defintions
#define CALL_PHONE 0x01  // sendTweet function command

class PhoneShieldClass 
{
public:
void call(char* );
private:
};
// instantiate object for users
extern PhoneShieldClass Phone;
#endif
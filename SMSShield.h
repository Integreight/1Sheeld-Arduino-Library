/*
  SMSShield.h - SMSShield library
  Copyright (C) 2013 Integreight Inc  All rights reserved.
*/
#ifndef SMSShield_h
#define SMSShield_h
// library defintions
#define SEND_SMS 0x01  
class SMSShieldClass 
{
public:
void send(char* ,char*);
private:
};
// instantiate object for users
extern SMSShieldClass SMS;
#endif
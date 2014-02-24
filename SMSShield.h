/*
  SMSShield.h - SMSShield library
  Copyright (C) 2013 Integreight Inc  All rights reserved.
*/
#ifndef SMSShield_h
#define SMSShield_h
// library defintions
#define SEND_SMS 0x01  
#define GET_SMS 0x01
class SMSShieldClass 
{
public:
	SMSShieldClass();
	void send(char* ,char*);
	char * getSms();
	char * getNumber();
private:
	void processData();
	char * text;
	char * number;
	friend class OneSheeldClass ;
};
// instantiate object for users
extern SMSShieldClass SMS;
#endif
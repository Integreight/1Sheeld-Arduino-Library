/*
  SMSShield.h - SMSShield library
  Copyright (C) 2013 Integreight Inc  All rights reserved.
*/
#ifndef PhoneShield_h
#define PhoneShield_h


// library defintions
#define CALL_PHONE 0x01  // sendTweet function command
#define IS_RINGING_VALUE 0x01
#define GET_NUMBER_VALUE 0x02
class PhoneShieldClass 
{
public:
PhoneShieldClass();
void call(char* );
bool isRinging();
char * getNumber();
void setOnChange(void (*)(bool , char *));
private:
	void processData();
	void (*changeCallBack)(bool , char *);
	bool isCallBackAssigned;
	byte value ;
	char * number;
	friend class OneSheeldClass ;
};
// instantiate object for users
extern PhoneShieldClass Phone;
#endif
/*
  TwitterShield.h - TwitterShield library
  Copyright (C) 2013 Integreight Inc  All rights reserved.
*/

#ifndef TwitterShield_h
#define TwitterShield_h

// library defintions
#define SEND_TWEET 0x01  // sendTweet function command
#define SEND_DIRECT_MESSAGE 0x02  // send direct message function command
#define GET_TWEET	0x01

class TwitterShieldClass 
{
public:
	TwitterShieldClass();
	void updateStatus(char* );
	void sendDirectMessage(char* ,char* );
	char * getUserName();
	char * getTweet();
	void setOnChange(void (*)(char*,char*));
private:
	char * userName;
	char * tweet;
	bool isCallBackAssigned;
	void processData();
	void (*changeCallBack)(char*,char*);
	friend class OneSheeldClass;




};
// instantiate object for users
extern TwitterShieldClass Twitter;
#endif
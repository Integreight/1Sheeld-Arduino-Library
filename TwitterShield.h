/*

  Project:       1Sheeld Library 
  File:          TwitterShield.h
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/

#ifndef TwitterShield_h
#define TwitterShield_h

//Output Function ID
#define SEND_TWEET 0x01  
//Input Functions ID's
#define SEND_DIRECT_MESSAGE 0x02 
#define GET_TWEET	0x01

class TwitterShieldClass 
{
public:
	//Constructor
	TwitterShieldClass();
	//Send tweet
	void tweet(char* );
	//Send Direct Message
	void sendDirectMessage(char* ,char* );
	//Getters 
	char * getUserName();
	char * getTweet();
	//setOnChange for Users Function
	void setOnNewTweet(void (*)(char*,char*));
private:
	//Reserve Variables
	char * userName;
	char * tweetText;
	//Boolean for setOnChange Function
	bool isCallBackAssigned;
	//Process Input Data 
	void processData();
	void (*changeCallBack)(char*,char*);

	friend class OneSheeldClass;




};
//Extern Object
extern TwitterShieldClass Twitter;
#endif
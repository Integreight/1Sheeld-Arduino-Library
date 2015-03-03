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

#include "ShieldParent.h"

//Output Function ID
#define TWITTER_SEND 				0x01  
#define TWITTER_SEND_DIRECT_MESSAGE 0x02
#define TWITTER_POST_LAST_PIC 0x03
#define TWITTER_TRACK_KEYWORD	0x04
#define TWITTER_UNTRACK_KEYWORD	0x05

//Input Functions ID's
#define TWITTER_GET_TWEET	0x01


class TwitterShieldClass : public ShieldParent
{
public:
	//Constructor
	TwitterShieldClass();
	//Send tweet
	void tweet(const char* );
	void tweet(String );
	//Send Direct Message
	void sendMessage(const char* ,const char* );
	void sendMessage(String , String);
	//Checkers
	bool isNewTweet();
	//Getters 
	char * getUserName();
	String getUserNameAsString();
	//Getters
	char * getTweet();
	String getTweetAsString();
	//setOnChange for Users Function
	void setOnNewTweet(void (*)(char [],char []));
	void setOnNewTweet(void (*)(String , String ));
	//Posting Pictures
	void tweetLastPicture(const char *,byte =0);
	void tweetLastPicture(String , byte =0);
	//Track certain words
	void trackKeyword(const char * );
	void trackKeyword(String );
	void untrackKeyword(const char *);
	void untrackKeyword(String);
	
private:
	//Reserve Variables
	char * userName;
	char * tweetText;
	//Boolean for setOnChange Function
	bool isCallBackAssigned;
	//Boolean for incoming String support
	bool usedSetOnWithString;
	//Boolean to check if a new tweet 
	bool isItNewTweet;
	//Process Input Data 
	void processData();
	void (*changeCallBack)(char [],char []);
	void (*changeCallBackString)(String , String);
};
//Extern Object
extern TwitterShieldClass Twitter;
#endif
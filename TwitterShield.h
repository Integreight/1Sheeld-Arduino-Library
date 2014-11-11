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
#define TWITTER_SEND 0x01  
#define TWITTER_SEND_DIRECT_MESSAGE 0x02
#define TWITTER_POST_LAST_PIC 0x03
#define TWITTER_TRACK_KEYWORD	0x04
#define TWITTER_UNTRACK_KEYWORD	0x05

//Input Functions ID's
#define TWITTER_GET_TWEET	0x01
#define TWITTER_CHECK_SELECTED 0x02

//Define Literals
#define FROM_ONESHEELD_FOLDER 0x00
#define FROM_CAMERA_FOLDER	  0x01

class TwitterShieldClass 
{
public:
	//Constructor
	TwitterShieldClass();
	//Send tweet
	void tweet(const char* );
	//Send Direct Message
	void sendMessage(const char* ,const char* );
	//Getters 
	char * getUserName();
	char * getTweet();
	//setOnChange for Users Function
	void setOnNewTweet(void (*)(char*,char*));
	//Posting Pictures
	void tweetLastPicture(const char *,byte =0);
	//Track certain words
	void trackKeyword(const char * );
	void untrackKeyword(const char *);
	//Check if shield selected
	void setOnTwitterSelected(void(*)(void));
private:
	//Reserve Variables
	char * userName;
	char * tweetText;
	//Boolean for setOnChange Function
	bool isCallBackAssigned;
	//Boolean for checking selection
	bool isCheckingTriggered;
	//Process Input Data 
	void processData();
	void (*changeCallBack)(char*,char*);
	void (*selectedCallBack)(void);

	friend class OneSheeldClass;




};
//Extern Object
extern TwitterShieldClass Twitter;
#endif
/*
  TwitterShield.h - TwitterShield library
  Copyright (C) 2013 Integreight Inc  All rights reserved.
*/

#include "OneSheeld.h"
#include "TwitterShield.h"

TwitterShieldClass::TwitterShieldClass()
{
 	userName = 0;
 	tweet = 0;
}
// public functions
void TwitterShieldClass::updateStatus( char *data)
{
OneSheeld.sendPacket(TWITTER_ID,0,SEND_TWEET,1,new FunctionArg(strlen(data),(byte*)data));
}
void TwitterShieldClass::sendDirectMessage(char* username,char* message)
{

	OneSheeld.sendPacket(TWITTER_ID,0,SEND_DIRECT_MESSAGE,2,new FunctionArg(strlen(username),(byte*)username),new FunctionArg(strlen(message),(byte*) message));

}

char * TwitterShieldClass::getUserName()
{
	return userName;
}

char * TwitterShieldClass::getTweet()
{
	return tweet;
}


void TwitterShieldClass::processData()
{
	byte functionId = OneSheeld.getFunctionId();
	if( functionId == GET_TWEET)
	{
		if(userName!=0)
		{
			free(userName);
		}
		if (tweet!=0)
		{
			free(tweet);
		}
		int userNameLength=OneSheeld.getArgumentLength(0);
		userName = (char*)malloc(sizeof(char)*(userNameLength+1));
		for (int j=0; j<userNameLength; j++)
		{
			userName[j]=OneSheeld.getArgumentData(0)[j];
		}
		userName[userNameLength]='\0';

		int tweetLength=OneSheeld.getArgumentLength(1);
		tweet = (char*)malloc(sizeof(char)*(tweetLength+1));

		for(int i=0 ;i<tweetLength;i++)
		{
			tweet[i]=OneSheeld.getArgumentData(1)[i];
		}
			tweet[tweetLength]='\0';

		if(isCallBackAssigned)
		{
			(*changeCallBack)(userName,tweet);
		}
	}
}

void TwitterShieldClass::setOnChange(void (*userFunction)(char * userName ,char * tweet))
{
	changeCallBack=userFunction;
	isCallBackAssigned=true;
}
// instantiate object for users
TwitterShieldClass Twitter;
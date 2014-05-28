/*

  Project:       1Sheeld Library 
  File:          TwitterShield.cpp
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/

#include "OneSheeld.h"
#include "TwitterShield.h"

//Class Constructor
TwitterShieldClass::TwitterShieldClass()
{
 	userName = 0;
 	tweetText = 0;
}
//Tweet Sender
void TwitterShieldClass::tweet( char *data)
{
OneSheeld.sendPacket(TWITTER_ID,0,SEND_TWEET,1,new FunctionArg(strlen(data),(byte*)data));
}
//Message Sender
void TwitterShieldClass::sendDirectMessage(char* username,char* message)
{

	OneSheeld.sendPacket(TWITTER_ID,0,SEND_DIRECT_MESSAGE,2,new FunctionArg(strlen(username),(byte*)username),new FunctionArg(strlen(message),(byte*) message));

}
//UserName Getter
char * TwitterShieldClass::getUserName()
{
	return userName;
}
//Tweet Getter
char * TwitterShieldClass::getTweet()
{
	return tweetText;
}
//Twitter Input Data Processing
void TwitterShieldClass::processData()
{
	//Checking Function-ID
	byte functionId = OneSheeld.getFunctionId();
	if( functionId == GET_TWEET)
	{
		if(userName!=0)
		{
			free(userName);
		}
		if (tweetText!=0)
		{
			free(tweetText);
		}
		int userNameLength=OneSheeld.getArgumentLength(0);
		userName = (char*)malloc(sizeof(char)*(userNameLength+1));
		for (int j=0; j<userNameLength; j++)
		{
			userName[j]=OneSheeld.getArgumentData(0)[j];
		}
		userName[userNameLength]='\0';

		int tweetLength=OneSheeld.getArgumentLength(1);
		tweetText = (char*)malloc(sizeof(char)*(tweetLength+1));

		for(int i=0 ;i<tweetLength;i++)
		{
			tweetText[i]=OneSheeld.getArgumentData(1)[i];
		}
			tweetText[tweetLength]='\0';
		//Users Function Invoked
		if(isCallBackAssigned)
		{
			(*changeCallBack)(userName,tweetText);
		}
	}
}
//Users Function Setter
void TwitterShieldClass::setOnNewTweet(void (*userFunction)(char * userName ,char * tweetText))
{
	changeCallBack=userFunction;
	isCallBackAssigned=true;
}

//Instantiating Object 
TwitterShieldClass Twitter;
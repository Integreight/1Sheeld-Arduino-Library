/*

  Project:       1Sheeld Library 
  File:          TwitterShield.cpp
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/
#define FROM_ONESHEELD_LIBRARY
#include "OneSheeld.h"
#include "TwitterShield.h"

//Class Constructor
TwitterShieldClass::TwitterShieldClass() : ShieldParent(TWITTER_ID)
{
 	userName = NULL;
 	tweetText = NULL;
 	isCallBackAssigned=false;
 	usedSetOnWithString=false;
 	isItNewTweet=false;
}
//Tweet Sender
void TwitterShieldClass::tweet(const char *data)
{
	//Check length of string 
	int dataLength = strlen(data);
	if(!dataLength) return;
	OneSheeld.sendShieldFrame(TWITTER_ID,0,TWITTER_SEND,1,new FunctionArg(dataLength,(byte*)data));
}

void TwitterShieldClass::tweet(String data)
{
	tweet(&data[0]);
}

//Message Sender
void TwitterShieldClass::sendMessage(const char* username,const char* message)
{
	//Check length of string 
	int usernameLength = strlen(username); 
	int messageLength = strlen(message);
	if(!usernameLength || !messageLength) return;
	OneSheeld.sendShieldFrame(TWITTER_ID,0,TWITTER_SEND_DIRECT_MESSAGE,2,new FunctionArg(usernameLength,(byte*)username),
																	new FunctionArg(messageLength,(byte*) message));

}

void TwitterShieldClass::sendMessage(String username , String message)
{
	sendMessage(&username[0],&message[0]);
}

void TwitterShieldClass::tweetLastPicture(const char * pictureText , byte imageSource)
{
	//Check length of string 
	int pictureTextLength = strlen(pictureText);
	if(!pictureTextLength) return;
	OneSheeld.sendShieldFrame(TWITTER_ID,0,TWITTER_POST_LAST_PIC,2,new FunctionArg(pictureTextLength,(byte*)pictureText),
															  new FunctionArg(1,(byte *)&imageSource));
}

void TwitterShieldClass::tweetLastPicture(String pictureText ,byte imageSource)
{
	tweetLastPicture(&pictureText[0],imageSource);
}

//Check if new tweet 
bool TwitterShieldClass::isNewTweet()
{
	return isItNewTweet;
}
void TwitterShieldClass::trackKeyword(const char * keyword)
{
	//Check length of string 
	int keywordLength = strlen(keyword);
	if(!keywordLength) return;
	OneSheeld.sendShieldFrame(TWITTER_ID,0,TWITTER_TRACK_KEYWORD,1,new FunctionArg(keywordLength,(byte*)keyword));
}

void TwitterShieldClass::untrackKeyword(const char * keyword)
{
	//Check length of string 
	int keywordLength = strlen(keyword);
	if(!keywordLength) return;
	OneSheeld.sendShieldFrame(TWITTER_ID,0,TWITTER_UNTRACK_KEYWORD,1,new FunctionArg(keywordLength,(byte*)keyword));
}

void TwitterShieldClass::trackKeyword(String keyword )
{
	trackKeyword(&keyword[0]);
}


void TwitterShieldClass::untrackKeyword(String keyword )
{
	untrackKeyword(&keyword[0]);
}

//UserName Getter
char * TwitterShieldClass::getUserName()
{
	isItNewTweet=false;
	return userName;
}

String TwitterShieldClass::getUserNameAsString()
{
	isItNewTweet=false;
	String userNameInString (userName);
	return userNameInString;
}
//Tweet Getter
char * TwitterShieldClass::getTweet()
{
	return tweetText;
}

String TwitterShieldClass::getTweetAsString()
{
	isItNewTweet=false;
	String tweetInString (tweetText);
	return tweetInString;
}
//Twitter Input Data Processing
void TwitterShieldClass::processData()
{
	//Checking Function-ID
	byte functionId = getOneSheeldInstance().getFunctionId();
	if( functionId == TWITTER_GET_TWEET)
	{	
		isItNewTweet = true;
		if(userName!=0)
		{
			free(userName);
		}
		if (tweetText!=0)
		{
			free(tweetText);
		}
		int userNameLength=getOneSheeldInstance().getArgumentLength(0);
		userName = (char*)malloc(sizeof(char)*(userNameLength+1));
		for (int j=0; j<userNameLength; j++)
		{
			userName[j]=getOneSheeldInstance().getArgumentData(0)[j];
		}
		userName[userNameLength]='\0';

		int tweetLength=getOneSheeldInstance().getArgumentLength(1);
		tweetText = (char*)malloc(sizeof(char)*(tweetLength+1));

		for(int i=0 ;i<tweetLength;i++)
		{
			tweetText[i]=getOneSheeldInstance().getArgumentData(1)[i];
		}
			tweetText[tweetLength]='\0';
		//Users Function Invoked
		if(!isInACallback())
		{
			if(isCallBackAssigned)
			{
				enteringACallback();
				(*changeCallBack)(userName,tweetText);
				exitingACallback();
			}

			if(usedSetOnWithString)
			{
				String usernameString(userName);
				String tweetTextString(tweetText);
				enteringACallback();
				(*changeCallBackString)(usernameString,tweetTextString);
				exitingACallback();
			}
		}
	}
}
//Users Function Setter
void TwitterShieldClass::setOnNewTweet(void (*userFunction)(char  userName [],char  tweetText []))
{
	changeCallBack=userFunction;
	isCallBackAssigned=true;
}

//Users Function Setter
void TwitterShieldClass::setOnNewTweet(void (*userFunction)(String userName ,String tweetText))
{
	changeCallBackString=userFunction;
	usedSetOnWithString=true;
}


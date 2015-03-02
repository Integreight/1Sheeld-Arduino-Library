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
	OneSheeld.sendPacket(TWITTER_ID,0,TWITTER_SEND,1,new FunctionArg(strlen(data),(byte*)data));
}
//Support string for Arduino
#if !defined(ARDUINO_LINUX)
void TwitterShieldClass::tweet(String data)
{
	const char * cTypeData = data.c_str();

	tweet(cTypeData);
}
#endif

//Support string for galileo
#if defined(ARDUINO_LINUX)
void TwitterShieldClass::tweet(String data)
{
	int dataLength = data.length();

	char cTypeData[dataLength+1];

	for (int i = 0; i <dataLength; i++)
	{
		cTypeData[i]=data[i];
	}
	cTypeData[dataLength]='\0';

	tweet(cTypeData);
}
#endif 

//Message Sender
void TwitterShieldClass::sendMessage(const char* username,const char* message)
{

	OneSheeld.sendPacket(TWITTER_ID,0,TWITTER_SEND_DIRECT_MESSAGE,2,new FunctionArg(strlen(username),(byte*)username),new FunctionArg(strlen(message),(byte*) message));

}

//Support string for Arduino
#if !defined(ARDUINO_LINUX)
void TwitterShieldClass::sendMessage(String username, String message)
{
	const char * cTypeUsername = username.c_str();
	const char * cTypeMessage = message.c_str();

	sendMessage(cTypeUsername,cTypeMessage);
}
#endif

//Support string for galileo
#if defined(ARDUINO_LINUX)
void TwitterShieldClass::sendMessage(String username , String message)
{
	int usernameLength = username.length();
	int messageLength = message.length();

	char cTypeUsername[usernameLength+1];
	char cTypeMessage[messageLength+1];

	for (int i = 0; i <usernameLength; i++)
	{
		cTypeUsername[i]=username[i];
	}
	cTypeUsername[usernameLength]='\0';

	for (int j = 0; j <messageLength; j++)
	{
		cTypeMessage[j]=message[j];
	}
	cTypeMessage[messageLength]='\0';

	sendMessage(cTypeUsername,cTypeMessage);
}
#endif

void TwitterShieldClass::tweetLastPicture(const char * pictureText , byte imageSource)
{
	OneSheeld.sendPacket(TWITTER_ID,0,TWITTER_POST_LAST_PIC,2,new FunctionArg(strlen(pictureText),(byte*)pictureText),new FunctionArg(1,(byte *)&imageSource));
}

//Support string for Arduino
#if !defined(ARDUINO_LINUX)
void TwitterShieldClass::tweetLastPicture(String pictureText , byte imageSource)
{
	const char * cTypePictureText = pictureText.c_str();

	tweetLastPicture(cTypePictureText,imageSource);
}
#endif

//Support string for galileo
#if defined(ARDUINO_LINUX)
void TwitterShieldClass::tweetLastPicture(String pictureText ,byte imageSource)
{
	int pictureTextLength = pictureText.length();

	char cTypePictureText[pictureTextLength+1];

	for (int i = 0; i <pictureTextLength; i++)
	{
		cTypePictureText[i]=pictureText[i];
	}
	cTypePictureText[pictureTextLength]='\0';

	tweetLastPicture(cTypePictureText,imageSource);
}
#endif
//Check if new tweet 
bool TwitterShieldClass::isNewTweet()
{
	return isItNewTweet;
}
void TwitterShieldClass::trackKeyword(const char * keyword)
{
	OneSheeld.sendPacket(TWITTER_ID,0,TWITTER_TRACK_KEYWORD,1,new FunctionArg(strlen(keyword),(byte*)keyword));
}

void TwitterShieldClass::untrackKeyword(const char * keyword)
{
	OneSheeld.sendPacket(TWITTER_ID,0,TWITTER_UNTRACK_KEYWORD,1,new FunctionArg(strlen(keyword),(byte*)keyword));
}

//Support string for Arduino
#if !defined(ARDUINO_LINUX)
void TwitterShieldClass::trackKeyword(String keyword )
{
	const char * cTypeKeyword = keyword.c_str();

	trackKeyword(cTypeKeyword);
}
#endif

//Support string for galileo
#if defined(ARDUINO_LINUX)
void TwitterShieldClass::trackKeyword(String keyword )
{
	int keywordLength = keyword.length();

	char cTypeKeyword[keywordLength+1];

	for (int i = 0; i <keywordLength; i++)
	{
		cTypeKeyword[i]=keyword[i];
	}
	cTypeKeyword[keywordLength]='\0';

	trackKeyword(cTypeKeyword);
}
#endif 


//Support string for Arduino
#if !defined(ARDUINO_LINUX)
void TwitterShieldClass::untrackKeyword(String keyword )
{
	const char * cTypeKeyword = keyword.c_str();

	untrackKeyword(cTypeKeyword);
}
#endif

//Support string for galileo
#if defined(ARDUINO_LINUX)
void TwitterShieldClass::untrackKeyword(String keyword )
{
	int keywordLength = keyword.length();

	char cTypeKeyword[keywordLength+1];

	for (int i = 0; i <keywordLength; i++)
	{
		cTypeKeyword[i]=keyword[i];
	}
	cTypeKeyword[keywordLength]='\0';

	untrackKeyword(cTypeKeyword);
}
#endif 
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
	byte functionId = OneSheeld.getFunctionId();
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
void TwitterShieldClass::setOnNewTweet(void (*userFunction)(char * userName ,char * tweetText))
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

#ifdef TWITTER_SHIELD
//Instantiating Object 
TwitterShieldClass Twitter;
#endif
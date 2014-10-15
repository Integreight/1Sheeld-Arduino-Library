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
	if( functionId == TWITTER_GET_TWEET)
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
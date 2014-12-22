/*

  Project:       1Sheeld Library 
  File:          FacebookShield.cpp
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/

#include "OneSheeld.h"
#include "FacebookShield.h"

//Post Sender
void FacebookShieldClass::post(const char* status)
{
	OneSheeld.sendPacket(FACEBOOK_ID,0,FACEBOOK_UPDATE_STATUS,1,new FunctionArg(strlen(status),(byte*)status));
}
//Support strings Arduino
#if !defined(ARDUINO_LINUX)
void FacebookShieldClass::post(String status)
{
	const char * cTypeStatus = status.c_str();

	post(cTypeStatus);
}
#endif

//Support string galileo 
#if defined(ARDUINO_LINUX)
void FacebookShieldClass::post(String status)
{
	int statusLength = status.length();

	char cTypeStatus [statusLength+1];

	for(int i=0; i<statusLength; i++)
	{
		cTypeStatus[i]=status[i];
	} 
	cTypeStatus[statusLength]='\0';

	post(cTypeStatus);
}
#endif

void FacebookShieldClass::postLastPicture(const char * pictureText, byte imageSource)
{
	OneSheeld.sendPacket(FACEBOOK_ID,0,FACEBOOK_POST_LAST_PIC,2,new FunctionArg(strlen(pictureText),(byte*)pictureText),new FunctionArg(1,(byte *)&imageSource));
}

//Support string and image source Arduino
#if !defined(ARDUINO_LINUX)
void FacebookShieldClass::postLastPicture(String pictureText , byte imageSource)
{
	const char * cTypePictureText = pictureText.c_str();

	postLastPicture(cTypePictureText,imageSource);
}
#endif

//Support string and image source galileo
#if defined(ARDUINO_LINUX)
void FacebookShieldClass::postLastPicture(String pictureText , byte imageSource)
{
	int pictureTextLength = pictureText.length();

	char cTypePictureText [pictureTextLength+1];

	for(int i=0 ;i<pictureTextLength;i++)
	{
		cTypePictureText[i] = pictureText[i];
	}
	cTypePictureText[pictureTextLength]='\0';

	postLastPicture(cTypePictureText,imageSource);
}
#endif

void FacebookShieldClass::select()
{
	OneSheeld.sendPacket(FACEBOOK_ID,0,FACEBOOK_SELECT_SHIELD,0);
}

void FacebookShieldClass::unselect()
{
	OneSheeld.sendPacket(FACEBOOK_ID,0,FACEBOOK_UNSELECT_SHIELD,0);
}

void FacebookShieldClass::processData()
{
	byte functionId = OneSheeld.getFunctionId();

	if(functionId == FACEBOOK_CHECK_SELECTED)
	{
		(*selectedCallBack)();
	}
}

void FacebookShieldClass::setOnSelected(void (*userFunction)(void))
{
	selectedCallBack=userFunction;
}
//Instantiating Object
FacebookShieldClass Facebook;
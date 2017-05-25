/*

  Project:       1Sheeld Library 
  File:          FacebookShield.cpp
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/
#define FROM_ONESHEELD_LIBRARY
#include "OneSheeld.h"
#include "FacebookShield.h"

//Post Sender
void FacebookShieldClass::post(const char* status)
{
	//Check length of string 
	int statusLength = strlen(status);
	if(!statusLength) return;
	OneSheeld.sendShieldFrame(FACEBOOK_ID,0,FACEBOOK_UPDATE_STATUS,1,new FunctionArg(statusLength,(byte*)status));
}

void FacebookShieldClass::post(String status)
{
	post(&status[0]);
}

void FacebookShieldClass::postLastPicture(const char * pictureText, byte imageSource)
{
	//Check length of string 
	int pictureTextLength = strlen(pictureText);
	if(!pictureTextLength) return;
	OneSheeld.sendShieldFrame(FACEBOOK_ID,0,FACEBOOK_POST_LAST_PIC,2,new FunctionArg(pictureTextLength,(byte*)pictureText),
																new FunctionArg(1,(byte *)&imageSource));
}

void FacebookShieldClass::postLastPicture(String pictureText , byte imageSource)
{
	postLastPicture(&pictureText[0],imageSource);
}


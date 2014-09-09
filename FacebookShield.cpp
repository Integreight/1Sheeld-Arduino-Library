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

void FacebookShieldClass::postLastPicture(char * pictureText, byte imageSource)
{
	OneSheeld.sendPacket(FACEBOOK_ID,0,FACEBOOK_POST_LAST_PIC,2,new FunctionArg(strlen(pictureText),(byte*)pictureText),new FunctionArg(1,(byte *)&imageSource));
}

//Instantiating Object
FacebookShieldClass Facebook;
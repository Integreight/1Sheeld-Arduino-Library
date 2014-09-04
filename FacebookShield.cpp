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
//Message Sender
void FacebookShieldClass::sendMessage(char * username,char * message)
{
	OneSheeld.sendPacket(FACEBOOK_ID,0,FACEBOOK_SEND_DIRECT_MESSAGE,2,new FunctionArg (strlen(username),(byte*)username),new FunctionArg(strlen(message),(byte*)message)); 
}

void FacebookShieldClass::postPicture(char * folderName, char * pictureName)
{
  OneSheeld.sendPacket(FACEBOOK_ID,0,FACEBOOK_POST_PICTURE,2,new FunctionArg (strlen(folderName),(byte*)folderName),new FunctionArg(strlen(pictureName),(byte*)pictureName)); 
}

//Instantiating Object
FacebookShieldClass Facebook;
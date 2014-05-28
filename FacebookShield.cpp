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
void FacebookShieldClass::post(char* status)
{
	OneSheeld.sendPacket(FACEBOOK_ID,0,UPDATE_STATUS,1,new FunctionArg(strlen(status),(byte*)status));
}
//Message Sender
void FacebookShieldClass::sendMessage(char * username,char * message)
{
	OneSheeld.sendPacket(FACEBOOK_ID,0,SEND_MESSAGE,2,new FunctionArg (strlen(username),(byte*)username),new FunctionArg(strlen(message),(byte*)message)); 
}

//Instantiating Object
FacebookShieldClass Facebook;
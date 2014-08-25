/*

  Project:       1Sheeld Library 
  File:          SkypeShield.cpp
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/

#include "OneSheeld.h"
#include "SkypeShield.h"

//Call Setter
void SkypeShieldClass::call(const char *username)
{
	OneSheeld.sendPacket(SKYPE_ID,0,SKYPE_CALL,1,new FunctionArg(strlen(username),(byte *)username));
}
//VideoCall Setter
void SkypeShieldClass::videoCall(const char * username)
{
	OneSheeld.sendPacket(SKYPE_ID,0,SKYPE_VIDEO_CALL,1,new FunctionArg(strlen(username),(byte *)username));
}

//Instantiating Object
SkypeShieldClass Skype;
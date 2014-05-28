/*

  Project:       1Sheeld Library 
  File:          SkyoeShield.cpp
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/

#include "OneSheeld.h"
#include "SkypeShield.h"

//Call Setter
void SkypeShieldClass::call(char *username)
{
	OneSheeld.sendPacket(SKYPE_ID,0,CALL,1,new FunctionArg(strlen(username),(byte *)username));
}
//VideoCall Setter
void SkypeShieldClass::videoCall(char * username)
{
	OneSheeld.sendPacket(SKYPE_ID,0,VIDEO_CALL,1,new FunctionArg(strlen(username),(byte *)username));
}

//Instantiating Object
SkypeShieldClass Skype;
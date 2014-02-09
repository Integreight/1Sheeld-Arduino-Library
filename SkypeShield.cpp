
#include "OneSheeld.h"
#include "SkypeShield.h"



SkypeShieldClass::SkypeShieldClass(){}

void SkypeShieldClass::call(char *username)
{
	

	OneSheeld.sendPacket(SKYPE_ID,0,CALL,1,new FunctionArg(strlen(username),(byte *)username));
}

void SkypeShieldClass::videoCall(char * username)
{
	OneSheeld.sendPacket(SKYPE_ID,0,VIDEO_CALL,1,new FunctionArg(strlen(username),(byte *)username));
}

void SkypeShieldClass::message(char* username,char* message)
{
	OneSheeld.sendPacket(SKYPE_ID,0,MESSAGE,2,new FunctionArg(strlen(username),(byte*)username),new FunctionArg(strlen(message),(byte*)message));
}

SkypeShieldClass Skype;
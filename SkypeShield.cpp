
#include "OneSheeld.h"
#include "SkypeShield.h"


void SkypeShieldClass::call(char *username)
{
	OneSheeld.sendPacket(SKYPE_ID,0,CALL,1,new FunctionArg(strlen(username),(byte *)username));
}

void SkypeShieldClass::videoCall(char * username)
{
	OneSheeld.sendPacket(SKYPE_ID,0,VIDEO_CALL,1,new FunctionArg(strlen(username),(byte *)username));
}

SkypeShieldClass Skype;
#include "OneSheeld.h"
#include "EmailShield.h"


EmailShieldClass::EmailShieldClass()
{}


void EmailShieldClass::send(char *username,char* message)
{
	OneSheeld.sendPacket(EMAIL_ID,0,SEND,2,new FunctionArg(strlen(username),(byte*)username),new FunctionArg(strlen(message),(byte*)message));
}

//instantiating object from the class 
EmailShieldClass Email;

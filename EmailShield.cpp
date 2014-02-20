#include "OneSheeld.h"
#include "EmailShield.h"


EmailShieldClass::EmailShieldClass()
{}


void EmailShieldClass::send(char *email ,char* message)
{
	OneSheeld.sendPacket(EMAIL_ID,0,SEND,2,new FunctionArg(strlen(email),(byte*)email),new FunctionArg(strlen(message),(byte*)message));
}

//instantiating object from the class 
EmailShieldClass Email;

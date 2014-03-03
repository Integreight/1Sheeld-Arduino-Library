#include "OneSheeld.h"
#include "EmailShield.h"

void EmailShieldClass::send(char *email ,char* subject,char* message)
{
	OneSheeld.sendPacket(EMAIL_ID,0,SEND,3,new FunctionArg(strlen(email),(byte*)email),new FunctionArg(strlen(subject),(byte*)subject),new FunctionArg(strlen(message),(byte*)message));
}

//instantiating object from the class 
EmailShieldClass Email;

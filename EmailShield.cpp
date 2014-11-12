/*

  Project:       1Sheeld Library 
  File:          EmailShield.cpp
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/

#include "OneSheeld.h"
#include "EmailShield.h"

//Email Sender
void EmailShieldClass::send(const char *email ,const char* subject,const char* message)
{
	OneSheeld.sendPacket(EMAIL_ID,0,EMAIL_SEND,3,new FunctionArg(strlen(email),(byte*)email),new FunctionArg(strlen(subject),(byte*)subject),new FunctionArg(strlen(message),(byte*)message));
}
//Attaching picture
void EmailShieldClass::attatchLastPicture(const char *email ,const char* subject,const char* message , byte imageSource)
{
	OneSheeld.sendPacket(EMAIL_ID,0,EMAIL_ATTATCH_PICTURE,4,new FunctionArg(strlen(email),(byte*)email),new FunctionArg(strlen(subject),(byte*)subject),new FunctionArg(strlen(message),(byte*)message),new FunctionArg(1,&imageSource));
}

//Instantiating object 
EmailShieldClass Email;

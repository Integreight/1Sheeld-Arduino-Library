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
void EmailShieldClass::send(char *email ,char* subject,char* message)
{
	OneSheeld.sendPacket(EMAIL_ID,0,SEND,3,new FunctionArg(strlen(email),(byte*)email),new FunctionArg(strlen(subject),(byte*)subject),new FunctionArg(strlen(message),(byte*)message));
}

//Instantiating object 
EmailShieldClass Email;

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
//Support strings Arduino
#if !defined(ARDUINO_LINUX)
void EmailShieldClass::send(String email, String subject , String message)
{
	const char * cTypeEmail = email.c_str();
	const char * cTypeSubject = subject.c_str();
	const char * cTypeMessage = message.c_str();

	send(cTypeEmail,cTypeSubject,cTypeMessage);
}
#endif
//Support strings galielo 
#if defined(ARDUINO_LINUX)
void EmailShieldClass::send(String email, String subject , String message)
{
	int emailLength = email.length();
	int subjectLength = subject.length();
	int messageLength = message.length();

	char cTypeEmail[emailLength+1];
	char cTypeSubject[subjectLength+1];
	char cTypeMessage[messageLength+1];

	for(int i=0 ;i<emailLength ;i++)
	{
		cTypeEmail[i]=email[i];
	}
	cTypeEmail[emailLength]='\0';

	for(int j=0 ;j<subjectLength ;j++)
	{
		cTypeSubject[j]=subject[j];
	}
	cTypeEmail[subjectLength]='\0';

	for(int k=0 ;k<emailLength ;k++)
	{
		cTypeMessage[k]=message[k];
	}
	cTypeEmail[messageLength]='\0';
}
#endif
//Instantiating object 
EmailShieldClass Email;

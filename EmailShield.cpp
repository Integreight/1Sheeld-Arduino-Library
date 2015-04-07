/*

  Project:       1Sheeld Library 
  File:          EmailShield.cpp
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/
#define FROM_ONESHEELD_LIBRARY
#include "OneSheeld.h"
#include "EmailShield.h"

//Email Sender
void EmailShieldClass::send(const char *email ,const char* subject,const char* message)
{
	//Check string length
	int emailLength = strlen(email);
	int subjectLength = strlen(subject);
	int messageLength = strlen(message);
	if(!emailLength||!subjectLength||!messageLength) return;
	OneSheeld.sendPacket(EMAIL_ID,0,EMAIL_SEND,3,new FunctionArg(emailLength,(byte*)email),
												 new FunctionArg(subjectLength,(byte*)subject),
												 new FunctionArg(messageLength,(byte*)message));
}

//Attaching picture
void EmailShieldClass::attachLastPicture(const char *email ,const char* subject,const char* message , byte imageSource)
{
	//Check email length
	int emailLength = strlen(email);
	if(!emailLength) return;
	//Check email length
	int subjectLength = strlen(subject);
	if(!subjectLength) return;
	//Check email length
	int messageLength = strlen(message);
	if(!messageLength) return;
	OneSheeld.sendPacket(EMAIL_ID,0,EMAIL_ATTACH_PICTURE,4,new FunctionArg(emailLength,(byte*)email),
														   new FunctionArg(subjectLength,(byte*)subject),
														   new FunctionArg(messageLength,(byte*)message),
														   new FunctionArg(1,&imageSource));
}

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
	cTypeSubject[subjectLength]='\0';

	for(int k=0 ;k<messageLength ;k++)
	{
		cTypeMessage[k]=message[k];
	}
	cTypeMessage[messageLength]='\0';

	send(cTypeEmail,cTypeSubject,cTypeMessage);
}

void EmailShieldClass::attachLastPicture(String email, String subject , String message , byte imageSource)
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
	cTypeSubject[subjectLength]='\0';

	for(int k=0 ;k<messageLength ;k++)
	{
		cTypeMessage[k]=message[k];
	}
	cTypeMessage[messageLength]='\0';

	attachLastPicture(cTypeEmail,cTypeSubject,cTypeMessage,imageSource);
}


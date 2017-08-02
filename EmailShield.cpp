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
	int emailLength = strlen(email);
	int subjectLength = strlen(subject);
	int messageLength = strlen(message);
	if(!emailLength||!subjectLength||!messageLength) return;
	OneSheeld.sendShieldFrame(EMAIL_ID,0,EMAIL_SEND,3,new FunctionArg(emailLength,(byte*)email),
												 new FunctionArg(subjectLength,(byte*)subject),
												 new FunctionArg(messageLength,(byte*)message));
}

void EmailShieldClass::send(String email, String subject , String message)
{

	send(&email[0],&subject[0],&message[0]);
}

//Attaching picture
void EmailShieldClass::attachLastPicture(const char *email ,const char* subject,const char* message , byte imageSource)
{
	int emailLength = strlen(email);
	int subjectLength = strlen(subject);
	int messageLength = strlen(message);
	if(!emailLength||!subjectLength||!messageLength) return;
	OneSheeld.sendShieldFrame(EMAIL_ID,0,EMAIL_ATTACH_FILE,4,new FunctionArg(emailLength,(byte*)email),
												 new FunctionArg(subjectLength,(byte*)subject),
												 new FunctionArg(messageLength,(byte*)message),
												 new FunctionArg(1,&imageSource));
}

void EmailShieldClass::attachLastPicture(String email, String subject , String message , byte imageSource)
{
	attachLastPicture(&email[0],&subject[0],&message[0],imageSource);
}

void EmailShieldClass::attachFile(int fileType)
{
	OneSheeld.sendShieldFrame(EMAIL_ID,0,EMAIL_ATTACH_FILE,1,new FunctionArg(2,(byte*)&fileType));
}

void EmailShieldClass::attachFile(const char * filePath)
{
	int filePathLength = strlen(filePath);
	if(!filePathLength) return;
	OneSheeld.sendShieldFrame(EMAIL_ID,0,EMAIL_ATTACH_FILE_PATH,1,new FunctionArg(filePathLength,(byte*)filePath));
}

void EmailShieldClass::attachFile(String filePath)
{
	attachFile(&filePath[0]);
}

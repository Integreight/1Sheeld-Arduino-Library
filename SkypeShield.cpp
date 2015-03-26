/*

  Project:       1Sheeld Library 
  File:          SkypeShield.cpp
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/
#include "OneSheeld.h"
#include "SkypeShield.h"

//Call Setter
void SkypeShieldClass::call(const char *username)
{
	//Check length of string 
	int usernameLength = strlen(username);
	if(!usernameLength) return;
	OneSheeld.sendPacket(SKYPE_ID,0,SKYPE_CALL,1,new FunctionArg(usernameLength,(byte *)username));
}

void SkypeShieldClass::call(String username)
{
	int usernameLength = username.length();

	char cTypeUsername[usernameLength+1];

	for (int i = 0; i < usernameLength; i++)
	{
		cTypeUsername[i]=username[i];
	}
	cTypeUsername[usernameLength]='\0';

	call(cTypeUsername);
}

//VideoCall Setter
void SkypeShieldClass::videoCall(const char * username)
{
	//Check length of string 
	int usernameLength = strlen(username);
	if(!usernameLength) return;
	OneSheeld.sendPacket(SKYPE_ID,0,SKYPE_VIDEO_CALL,1,new FunctionArg(usernameLength,(byte *)username));
}

void SkypeShieldClass::videoCall(String username)
{
	int usernameLength = username.length();

	char cTypeUsername[usernameLength+1];

	for (int i = 0; i < usernameLength; i++)
	{
		cTypeUsername[i]=username[i];
	}
	cTypeUsername[usernameLength]='\0';

	call(cTypeUsername);
}

#ifdef SKYPE_SHIELD
//Instantiating Object
SkypeShieldClass Skype;
#endif
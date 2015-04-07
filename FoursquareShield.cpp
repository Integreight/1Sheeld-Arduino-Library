/*

  Project:       1Sheeld Library 
  File:          FoursquareShield.cpp
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/
#define FROM_ONESHEELD_LIBRARY
#include "OneSheeld.h"
#include "FoursquareShield.h"


//Checking-In Sender
void FoursquareShieldClass::checkIn(const char* placeId,const char* message)
{
	//Check length of string 
	int placeIdLength = strlen(placeId);
	int messageLength = strlen(message);
	if(!placeIdLength || !messageLength) return;
	OneSheeld.sendPacket(FOURSQUARE_ID,0,FOURSQUARE_CHECK_IN,2,new FunctionArg(placeIdLength,(byte*)placeId),
															   new FunctionArg(messageLength,(byte*)message));
}

void FoursquareShieldClass::checkIn(String placeId , String message)
{
	int placeIdLength = placeId.length();
	int messageLegnth = message.length();

	char cTypePlaceId [placeIdLength+1];
	char cTypeMessage [messageLegnth+1];

	for (int i=0 ;i <placeIdLength ;i++)
	{
		cTypePlaceId[i] = placeId [i];
	}
	cTypePlaceId[placeIdLength]='\0';

	for(int j=0 ;j<messageLegnth ;j++)
	{
		cTypeMessage[j] = message[j];
	}
	cTypeMessage[messageLegnth]='\0';

	checkIn(cTypePlaceId,cTypeMessage);
}


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
	OneSheeld.sendShieldFrame(FOURSQUARE_ID,0,FOURSQUARE_CHECK_IN,2,new FunctionArg(placeIdLength,(byte*)placeId),
															   new FunctionArg(messageLength,(byte*)message));
}

void FoursquareShieldClass::checkIn(String placeId , String message)
{
	checkIn(&placeId[0],&message[0]);
}


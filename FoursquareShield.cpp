/*

  Project:       1Sheeld Library 
  File:          FoursquareShield.cpp
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/

#include "OneSheeld.h"
#include "FoursquareShield.h"


//Checking-In Sender
void FoursquareShieldClass::checkIn(char* placeId, char* msg)
{
	OneSheeld.sendPacket(FOURSQUARE_ID,0,CHECK_IN,2,new FunctionArg(strlen(placeId),(byte*)placeId),new FunctionArg(strlen(msg),(byte*)msg));
}

//Instantiating Object
FoursquareShieldClass Foursquare;
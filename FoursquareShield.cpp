#include "OneSheeld.h"
#include "FoursquareShield.h"



void FoursquareShieldClass::checkIn(char* placeId, char* msg)
{
	OneSheeld.sendPacket(FOURSQUARE_ID,0,CHECK_IN,2,new FunctionArg(strlen(placeId),(byte*)placeId),new FunctionArg(strlen(msg),(byte*)msg));
}

FoursquareShieldClass Foursquare;
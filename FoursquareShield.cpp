#include "OneSheeld.h"
#include "FoursquareShield.h"


FoursquareShieldClass::FoursquareShieldClass()
{}



void FoursquareShieldClass::checkIn(char* placeName)
{
	OneSheeld.sendPacket(FOURSQUARE_ID,0,CHECK_IN,1,new FunctionArg(strlen(placeName),(byte*)placeName));
}

FoursquareShieldClass FSQ;
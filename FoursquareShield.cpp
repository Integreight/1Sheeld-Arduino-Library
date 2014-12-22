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
void FoursquareShieldClass::checkIn(const char* placeId,const char* message)
{
	OneSheeld.sendPacket(FOURSQUARE_ID,0,FOURSQUARE_CHECK_IN,2,new FunctionArg(strlen(placeId),(byte*)placeId),new FunctionArg(strlen(message),(byte*)message));
}

//Support string for Arduino
#if !defined(ARDUINO_LINUX)
void FoursquareShieldClass::checkIn(String placeId , String message)
{
	const char * cTypePlaceId = placeId.c_str();
	const char * cTypeMessage = message.c_str();

	checkIn(cTypePlaceId,cTypeMessage);
}
#endif

//Support string for galielo
#if defined(ARDUINO_LINUX)
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
#endif

void FoursquareShieldClass::select()
{
	OneSheeld.sendPacket(FOURSQUARE_ID,0,FOURSQUARE_SELECT_SHIELD,0);
}

void FoursquareShieldClass::unselect()
{
	OneSheeld.sendPacket(FOURSQUARE_ID,0,FOURSQUARE_UNSELECT_SHIELD,0);
}

void FoursquareShieldClass::processData()
{
	byte functionId = OneSheeld.getFunctionId();

	if(functionId == FOURSQUARE_CHECK_SELECTED)
	{
		(*selectedCallBack)();
	}
}

void FoursquareShieldClass::setOnSelected(void (*userFunction)(void))
{
	selectedCallBack=userFunction;
}
//Instantiating Object
FoursquareShieldClass Foursquare;
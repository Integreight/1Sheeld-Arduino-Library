/*

  Project:       1Sheeld Library 
  File:          NotificationShield.cpp
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/
#include "OneSheeld.h"
#include "NotificationShield.h"

//Notification Sender
void NotificationShieldClass::notifyPhone(const char* data)
{
	OneSheeld.sendPacket(NOTIFICATION_ID,0,NOTIFICATION_NOTIFY_PHONE,1,new FunctionArg(strlen(data),(byte*)data));
}

//Support string for Arduino
#if !defined(ARDUINO_LINUX) 
void NotificationShieldClass::notifyPhone(String data)
{
	const char * ctypeData = data.c_str();

	notifyPhone(ctypeData);
}
#endif

//Support string for galileo
#if defined(ARDUINO_LINUX)
void NotificationShieldClass::notifyPhone(String data)
{
	int dataLength = data.length();

	char cTypeData [dataLength+1];

	for(int i=0 ;i<dataLength;i++)
	{
		cTypeData[i] = data[i];
	}
	cTypeData[dataLength]='\0';

	notifyPhone(cTypeData);
}
#endif

#ifdef NOTIFICATION_SHIELD
//Instantiating Object
NotificationShieldClass Notification;
#endif
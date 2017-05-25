/*

  Project:       1Sheeld Library 
  File:          NotificationShield.cpp
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/
#define FROM_ONESHEELD_LIBRARY
#include "OneSheeld.h"
#include "NotificationShield.h"

//Notification Sender
void NotificationShieldClass::notifyPhone(const char* data)
{
	//Check length of string 
	int dataLength = strlen(data);
	if(!dataLength) return;
	OneSheeld.sendShieldFrame(NOTIFICATION_ID,0,NOTIFICATION_NOTIFY_PHONE,1,new FunctionArg(dataLength,(byte*)data));
}

void NotificationShieldClass::notifyPhone(String data)
{
	notifyPhone(&data[0]);
}


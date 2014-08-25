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

//Instantiating Object
NotificationShieldClass Notification;
/*
  NotificationShield.h - NotificationShield library
  Copyright (C) 2013 Integreight Inc  All rights reserved.
*/

#include "OneSheeld.h"
#include "NotificationShield.h"

// public functions
NotificationShieldClass::NotificationShieldClass(){}
void NotificationShieldClass::notifyPhone(char* data)
{
OneSheeld.sendPacket(NOTIFICATION_ID,0,NOTIFY_PHONE,1,new FunctionArg(strlen(data),(byte*)data));
}

// instantiate object for users
NotificationShieldClass Notification;
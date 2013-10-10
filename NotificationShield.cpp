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
OneSheeld.write(NOTIFICATION_ID,NOTIFY_PHONE,data);
}

// instantiate object for users
NotificationShieldClass Notification;
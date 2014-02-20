/*
  NotificationShield.h - NotificationShield library
  Copyright (C) 2013 Integreight Inc  All rights reserved.
*/
#ifndef NotificationShield_h
#define NotificationShield_h

// library defintions
#define NOTIFY_PHONE 0x01  // sendTweet function command

class NotificationShieldClass 
{
public:
void notifyPhone(char* );

private:



};
// instantiate object for users
extern NotificationShieldClass Notification;
#endif
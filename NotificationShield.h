/*
  NotificationShield.h - NotificationShield library
  Copyright (C) 2013 Integreight Inc  All rights reserved.
*/
#ifndef NotificationShield_h
#define NotificationShield_h

// library defintions
#define NOTIFICATION_ID 0x34  // twitter shield id 
#define NOTIFY_PHONE 0x01  // sendTweet function command

class NotificationShieldClass 
{
public:
NotificationShieldClass();
void notifyPhone(char* data);

private:



};
// instantiate object for users
extern NotificationShieldClass Notification;
#endif
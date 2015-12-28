/*

  Project:       1Sheeld Library 
  File:          NotificationShield.h
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/

#ifndef NotificationShield_h
#define NotificationShield_h

#include "ShieldParent.h"
#include "IncomingNotification.h"
//Output Function ID
#define NOTIFICATION_NOTIFY_PHONE 0x01

//Input Function ID
#define NOTIFICATION_INCOMING	0x01
#define NOTIFICATION_ON_DATA_QUERY	0x02


class NotificationShieldClass : public ShieldParent
{
public:
	//Constructror
	NotificationShieldClass();
	//Sender 
	void notifyPhone(const char* );
	void notifyPhone(String );
	void onNewNotification(void (*)(byte , char [],IncomingNotification &));
	void onDataQueryResponse(void(*)(byte , byte , char [], byte ));
	
private:
	bool isOnNewCallBackAssigned;
	bool isOnDataQueryCallBackAssigned;
	void (*onNewNotificationCallback)(byte ,char [],IncomingNotification &);
	void (*onQueryDataCallback)(byte, byte , char [],byte);
	void processData();
};

//Extern Object
extern NotificationShieldClass Notification;
#endif
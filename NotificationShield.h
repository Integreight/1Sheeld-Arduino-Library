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
#define NOTIFICATION_ON_NEW_MESSAGE 0x03
#define NOTIFICATION_ON_DIMISS		0x04
#define NOTIFICATION_ON_ERROR		0x05


//Error Types
#define NOTIFICATION_NOT_FOUND_OR_DISMISSED 0x0A
#define NO_DATA 	0x0B

//Application Types
#define FACEBOOK	0x01
#define WHATS_APP	0x02
#define GMAIL		0x03
#define HANGOUTS	0x04
#define TELEGRAM	0x05
#define LINE		0x06
#define SLACK		0x07

class NotificationShieldClass : public ShieldParent
{
public:
	//Constructror
	NotificationShieldClass();
	//Sender 
	void notifyPhone(const char* );
	void notifyPhone(String );
	void onNewNotification(void (*)(int ,const char [],IncomingNotification &));
	void onDataQueryResponse(void(*)(int , byte ,const char [], byte ));
	void onNewMessageNotification(void(*)(int , byte ,const char [], const char [], byte ));
	void onDismiss(void(*)(int ));
	void onError(void(*)(int , byte ));

	
private:
	bool isOnNewCallBackAssigned;
	bool isOnDataQueryCallBackAssigned;
	bool isNewMessageCallBackAssigned;
	bool isDismissedCallBackAssigned;
	bool isErrorCallBackAssigned;
	void (*onNewNotificationCallback)(int ,const char [],IncomingNotification &);
	void (*onQueryDataCallback)(int, byte , const char [],byte);
	void (*onNewMessageCallback)(int,byte,const char [], const char[],byte);
	void (*onDimissCallback)(int);
	void (*onErrorCallback)(int, byte);
	void processData();
};

//Extern Object
extern NotificationShieldClass Notification;
#endif
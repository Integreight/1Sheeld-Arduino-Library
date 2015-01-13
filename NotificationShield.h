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

//Output Function ID
#define NOTIFICATION_NOTIFY_PHONE 0x01
#define	NOTIFICATION_SELECT_SHIELD	0xFE
#define NOTIFICATION_UNSELECT_SHIELD 0xFD

//Input Function ID
#define NOTIFICATION_CHECK_SELECTED	0xFF

class NotificationShieldClass 
{
public:
	//Sender 
	void notifyPhone(const char* );
	void notifyPhone(String );
	//Selection
	void select();
	void unselect();
	//Set On when Selected
	void setOnSelected(void (*)(void));
private:
	void processData();
	void (*selectedCallBack)(void);

	friend class OneSheeldClass;
};

//Extern Object
extern NotificationShieldClass Notification;
#endif
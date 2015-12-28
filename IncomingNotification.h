/*

  Project:       1Sheeld Library 
  File:          NotificationShield.h
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/

#ifndef IncomingNotification_h
#define IncomingNotification_h


#define NOTIFICATION_QUERY_DATA	  0x02	
  
#define BIG_TICKER_BIT 0
#define BIG_TITLE_BIT 1
#define TEXT_LINES_BIT 2 
#define BIG_TEXT_BIT 3 
#define INFO_TEXT_BIT 4
#define SUB_TEXT_BIT 5
#define TEXT_BIT 6
#define TITLE_BIT 7

struct IncomingNotification
{
	IncomingNotification(byte);
	byte notificationId; 
	byte notificationType;
	char * appName; 
	long timeStamp;
	byte getId();
	long getTimeStamp();
	bool hasTitle();
	bool hasText();
	bool hasSubText();
	bool hasInfoText();
	bool hasBigText();
	bool hasTextLines();
	bool hasBigTitle();
	bool hasBigTicker();
	void queryApp();
	void queryTitle();
	void queryText();
	void querySubText();
	void queryInfoText();
	void queryBigText();
	void queryTextLines();
	void queryBigTitle();
	void queryBigTicker();
};

#endif
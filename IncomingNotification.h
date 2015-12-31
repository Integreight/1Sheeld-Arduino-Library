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

// Output Function ID
#define NOTIFICATION_QUERY_DATA	  0x02
#define NOTIFICATION_DIMISS		  0x03	
  
#define TICKER_BIT 0
#define BIG_TITLE_BIT 1
#define TEXT_LINES_BIT 2 
#define BIG_TEXT_BIT 3 
#define INFO_TEXT_BIT 4
#define SUB_TEXT_BIT 5
#define TEXT_BIT 6
#define TITLE_BIT 7

#define NO_APP_NAME		0x01
#define NO_TITLE		0x02
#define NO_TEXT			0x03
#define NO_SUB_TEXT		0x04
#define NO_INFO_TEXT	0x05
#define NO_BIG_TEXT		0x06
#define NO_TEXT_LINES	0x07
#define NO_BIG_TITLE	0x08
#define NO_TICKER		0x09

struct IncomingNotification
{
	IncomingNotification(int);
	int notificationId; 
	byte notificationType;
	char * appName; 
	unsigned long timeStamp;
	int getId();
	unsigned long getTimeStamp();
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
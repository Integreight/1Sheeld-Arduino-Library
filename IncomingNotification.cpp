/*

  Project:       1Sheeld Library 
  File:          NotificationShield.cpp
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/
#define FROM_ONESHEELD_LIBRARY
#include "OneSheeld.h"
#include "IncomingNotification.h"

IncomingNotification::IncomingNotification(int id)
{
	notificationId= id;
}

int IncomingNotification::getId()
{ 
	return notificationId;
}
unsigned long IncomingNotification::getTimeStamp()
{
	return timeStamp;
}
bool IncomingNotification::hasTitle()
{
	return !!(notificationType & (1<<TITLE_BIT));
}
bool IncomingNotification::hasText()
{
	return !!(notificationType & (1<<TEXT_BIT));
}
bool IncomingNotification::hasSubText()
{
	return !!(notificationType & (1<<SUB_TEXT_BIT));
}
bool IncomingNotification::hasInfoText()
{
	return !!(notificationType & (1<<INFO_TEXT_BIT));
}
bool IncomingNotification::hasBigText()
{
	return !!(notificationType & (1<<BIG_TEXT_BIT));
}
bool IncomingNotification::hasTextLines()
{
	return !!(notificationType & (1<<TEXT_LINES_BIT));
}
bool IncomingNotification::hasBigTitle()
{
	return !!(notificationType & (1<<BIG_TITLE_BIT));
}
bool IncomingNotification::hasBigTicker()
{
	return !!(notificationType & (1<<BIG_TICKER_BIT));
}
void IncomingNotification::queryApp()
{
	int queryType = 0; 
	queryType |= 0x100;
	OneSheeld.sendShieldFrame(NOTIFICATION_ID,0,NOTIFICATION_QUERY_DATA,2,new FunctionArg(1,&notificationId)
																		 ,new FunctionArg(sizeof(uint16_t),(byte*)&queryType));
}
void IncomingNotification::queryTitle()
{
	byte queryType = 0; 
	queryType |= 0x80;
	OneSheeld.sendShieldFrame(NOTIFICATION_ID,0,NOTIFICATION_QUERY_DATA,2,new FunctionArg(1,&notificationId)
																		,new FunctionArg(1,&queryType));
}
void IncomingNotification::queryText()
{
	byte queryType = 0; 
	queryType |= 0x40;
	OneSheeld.sendShieldFrame(NOTIFICATION_ID,0,NOTIFICATION_QUERY_DATA,2,new FunctionArg(1,&notificationId)
																		,new FunctionArg(1,&queryType));
}
void IncomingNotification::querySubText()
{
	byte queryType = 0; 
	queryType |= 0x20;
	OneSheeld.sendShieldFrame(NOTIFICATION_ID,0,NOTIFICATION_QUERY_DATA,2,new FunctionArg(1,&notificationId)
																		,new FunctionArg(1,&queryType));
}
void IncomingNotification::queryInfoText()
{
	byte queryType = 0; 
	queryType |= 0x10;
	OneSheeld.sendShieldFrame(NOTIFICATION_ID,0,NOTIFICATION_QUERY_DATA,2,new FunctionArg(1,&notificationId)
																		,new FunctionArg(1,&queryType));
}
void IncomingNotification::queryBigText()
{
	byte queryType = 0; 
	queryType |= 0x08;
	OneSheeld.sendShieldFrame(NOTIFICATION_ID,0,NOTIFICATION_QUERY_DATA,2,new FunctionArg(1,&notificationId)
																		,new FunctionArg(1,&queryType));
}
void IncomingNotification::queryTextLines()
{
	byte queryType = 0; 
	queryType |= 0x04;
	OneSheeld.sendShieldFrame(NOTIFICATION_ID,0,NOTIFICATION_QUERY_DATA,2,new FunctionArg(1,&notificationId)
																		,new FunctionArg(1,&queryType));
}
void IncomingNotification::queryBigTitle()
{
	byte queryType = 0; 
	queryType |= 0x02;
	OneSheeld.sendShieldFrame(NOTIFICATION_ID,0,NOTIFICATION_QUERY_DATA,2,new FunctionArg(1,&notificationId)
																		,new FunctionArg(1,&queryType));
}
void IncomingNotification::queryBigTicker()
{
	byte queryType = 0; 
	queryType |= 0x01;
	OneSheeld.sendShieldFrame(NOTIFICATION_ID,0,NOTIFICATION_QUERY_DATA,2,new FunctionArg(1,&notificationId)
																		,new FunctionArg(1,&queryType));
}
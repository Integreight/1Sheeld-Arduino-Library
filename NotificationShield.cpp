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
#include "NotificationShield.h"

NotificationShieldClass::NotificationShieldClass():ShieldParent(NOTIFICATION_ID)
{
	isOnNewCallBackAssigned = false;
	isOnDataQueryCallBackAssigned =false;
}
//Notification Sender
void NotificationShieldClass::notifyPhone(const char* data)
{
	//Check length of string 
	int dataLength = strlen(data);
	if(!dataLength) return;
	OneSheeld.sendShieldFrame(NOTIFICATION_ID,0,NOTIFICATION_NOTIFY_PHONE,1,new FunctionArg(dataLength,(byte*)data));
}

void NotificationShieldClass::notifyPhone(String data)
{
	int dataLength = data.length();

	char cTypeData [dataLength+1];

	for(int i=0 ;i<dataLength;i++)
	{
		cTypeData[i] = data[i];
	}
	cTypeData[dataLength]='\0';

	notifyPhone(cTypeData);
}

void NotificationShieldClass::processData()
{
	byte functionId = getOneSheeldInstance().getFunctionId();
	if(functionId == NOTIFICATION_INCOMING)
	{
		IncomingNotification myNotification(getOneSheeldInstance().getArgumentData(0)[0]);
		byte appNameLength =  getOneSheeldInstance().getArgumentLength(1); 
		char appName[appNameLength+1];
		for(int i =0 ; i< appNameLength;i++)
		{
			appName[i]=getOneSheeldInstance().getArgumentData(1)[i];
		}
		appName[appNameLength] = '\0';
		myNotification.timeStamp = (unsigned long)getOneSheeldInstance().getArgumentData(2)[0]
					 		|(((unsigned long)getOneSheeldInstance().getArgumentData(2)[1])<<8)
					 		|(((unsigned long)getOneSheeldInstance().getArgumentData(2)[2])<<16)
					 		|(((unsigned long)getOneSheeldInstance().getArgumentData(2)[3])<<24);
 		myNotification.notificationType =  getOneSheeldInstance().getArgumentData(3)[0];
		//Invoke Users function
		if(!isInACallback())
		{
			if(isOnNewCallBackAssigned)
			{
				enteringACallback();
				(*onNewNotificationCallback)(myNotification.notificationId,appName,myNotification);
				exitingACallback();
			}
		}
		
	}else if(functionId == NOTIFICATION_ON_DATA_QUERY)
	{
		byte incomingId = getOneSheeldInstance().getArgumentData(0)[0];
		byte incomingType = getOneSheeldInstance().getArgumentData(1)[0];
		int onQueryDataLength = getOneSheeldInstance().getArgumentLength(2);
		char onQueryData[onQueryDataLength+1];
		for(int i =0 ; i < onQueryDataLength;i++)
		{
			onQueryData[i] = getOneSheeldInstance().getArgumentData(2)[i];
		}
		onQueryData[onQueryDataLength]= '\0';
		byte dataSize = getOneSheeldInstance().getArgumentLength(2);
		//Invoke Users function
		if(!isInACallback())
		{
			if(isOnDataQueryCallBackAssigned)
			{
				enteringACallback();
				(*onQueryDataCallback)(incomingId,incomingType,onQueryData,dataSize);
				exitingACallback();
			}
		}
	}
}

void NotificationShieldClass::onNewNotification(void (*userFunction)(byte , char [],IncomingNotification &))
{
	isOnNewCallBackAssigned = true;
	onNewNotificationCallback = userFunction;
}

void NotificationShieldClass::onDataQueryResponse(void(*userFunction)(byte , byte , char [], byte ))
{
	isOnDataQueryCallBackAssigned = true;
	onQueryDataCallback = userFunction;
}
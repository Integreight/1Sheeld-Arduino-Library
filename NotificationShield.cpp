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
	isNewMessageCallBackAssigned = false;
	isDismissedCallBackAssigned = false;
	isErrorCallBackAssigned = false;
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
		int incomingId = getOneSheeldInstance().getArgumentData(0)[0]|((getOneSheeldInstance().getArgumentData(0)[1])<<8);
		IncomingNotification myNotification(incomingId);
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
		int incomingId = getOneSheeldInstance().getArgumentData(0)[0]|((getOneSheeldInstance().getArgumentData(0)[1])<<8);
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
	}else if(functionId == NOTIFICATION_ON_NEW_MESSAGE)
	{
		int incomingId = getOneSheeldInstance().getArgumentData(0)[0]|((getOneSheeldInstance().getArgumentData(0)[1])<<8);
		byte appType = getOneSheeldInstance().getArgumentData(1)[0];
		int userNameLength = getOneSheeldInstance().getArgumentLength(2);
		char userName[userNameLength+1];
		for(int i =0 ; i < userNameLength;i++)
		{
			userName[i] = getOneSheeldInstance().getArgumentData(2)[i];
		}
		userName[userNameLength]= '\0';
	
		int appDataLength = getOneSheeldInstance().getArgumentLength(3);
		char appData[appDataLength+1];
		for(int i =0 ; i < appDataLength;i++)
		{
			appData[i] = getOneSheeldInstance().getArgumentData(3)[i];
		}
		appData[appDataLength]= '\0';
		byte dataSize = getOneSheeldInstance().getArgumentLength(3);
		//Invoke Users function
		if(!isInACallback())
		{
			if(isNewMessageCallBackAssigned)
			{
				enteringACallback();
				(*onNewMessageCallback)(incomingId,appType,userName,appData,dataSize);
				exitingACallback();
			}
		}
	}else if(functionId == NOTIFICATION_ON_DIMISS)
	{
		int incomingId = getOneSheeldInstance().getArgumentData(0)[0]|((getOneSheeldInstance().getArgumentData(0)[1])<<8);
		//Invoke Users function
		if(!isInACallback())
		{
			if(isDismissedCallBackAssigned)
			{
				enteringACallback();
				(*onDimissCallback)(incomingId);
				exitingACallback();
			}
		}
	}else if(functionId == NOTIFICATION_ON_ERROR)
	{
		int incomingId = getOneSheeldInstance().getArgumentData(0)[0]|((getOneSheeldInstance().getArgumentData(0)[1])<<8);
		byte errorType = getOneSheeldInstance().getArgumentData(1)[0];
		//Invoke Users function
		if(!isInACallback())
		{
			if(isErrorCallBackAssigned)
			{
				enteringACallback();
				(*onErrorCallback)(incomingId,errorType);
				exitingACallback();
			}
		}
	}
}

void NotificationShieldClass::onNewNotification(void (*userFunction)(int , const char [],IncomingNotification &))
{
	isOnNewCallBackAssigned = true;
	onNewNotificationCallback = userFunction;
}

void NotificationShieldClass::onDataQueryResponse(void(*userFunction)(int , byte ,const char [], byte ))
{
	isOnDataQueryCallBackAssigned = true;
	onQueryDataCallback = userFunction;
}

void NotificationShieldClass::onNewMessageNotification(void(*userFunction)(int , byte ,const char [], const char [], byte ))
{
	isNewMessageCallBackAssigned = true;
	onNewMessageCallback = userFunction;
}

void NotificationShieldClass::onDismiss(void(*userFunction)(int ))
{
	isDismissedCallBackAssigned = true;
	onDimissCallback = userFunction;
}

void NotificationShieldClass::onError(void(*userFunction)(int , byte ))
{
	isErrorCallBackAssigned = true;
	onErrorCallback = userFunction;
}
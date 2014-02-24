/*
  SMSShield.h - SMSShield library
  Copyright (C) 2013 Integreight Inc  All rights reserved.
*/
#include "OneSheeld.h"
#include "SMSShield.h"

// public functions
  SMSShieldClass::SMSShieldClass()
  {
  	text=0;
  }
void SMSShieldClass::send(char* number,char* text)
{
	OneSheeld.sendPacket(SMS_ID,0,SEND_SMS,2,new FunctionArg(strlen(number),(byte*)number),new FunctionArg(strlen(text),(byte*)text));
}

void SMSShieldClass::processData()
{
	byte x= OneSheeld.getFunctionId();
	if(x==GET_SMS)
	{
		if(text!=0)
		{
			free(text);
		}
		int length=OneSheeld.getArgumentLength(0);
		
		text=(char*)malloc(sizeof(char)*(length+1));

		for(int i=0 ;i<length;i++)
		{
			text[i]=OneSheeld.getArgumentData(0)[i];
		}
			text[length]='\0';
	}
}

char * SMSShieldClass::getSms()
{
	return text;
}
// instantiate object for users
SMSShieldClass SMS;
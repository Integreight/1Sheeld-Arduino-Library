/*
  SMSShield.h - SMSShield library
  Copyright (C) 2013 Integreight Inc  All rights reserved.
*/

#include "OneSheeld.h"
#include "SMSShield.h"

// public functions
SMSShieldClass::SMSShieldClass(){}
void SMSShieldClass::send(char* number,char* text)
{
	/*
	char str[140];
	strcpy (str, ""); //inserting a null in the array because strcat search for null to concatenate the string comes after the first null str[0]='\0'
	strcat (str, number);
	strcat (str, "##");
	strcat (str, text);
	*/
	OneSheeld.sendPacket(SMS_ID,0,SEND_SMS,2,new FunctionArg(strlen(number),(byte*)number),new FunctionArg(strlen(text),(byte*)text));
}

// instantiate object for users
SMSShieldClass SMS;
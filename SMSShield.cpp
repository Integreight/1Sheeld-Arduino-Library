/*

  Project:       1Sheeld Library 
  File:          SMSShield.cpp
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/
#include "OneSheeld.h"
#include "SMSShield.h"

//Class Constructor
 SMSShieldClass::SMSShieldClass() : ShieldParent(SMS_ID)
  {
  	text=NULL;
  	number=NULL;
  	isCallBackAssigned=false;
  	isItNewSms=false;
  	usedSetOnWithString=false;
  }
//SMS Sender
void SMSShieldClass::send(const char* number,const char* text)
{
	//Check length of string 
	int numberLength = strlen(number); 
	int textLength = strlen(text);
	if(!numberLength || !textLength) return;
	OneSheeld.sendPacket(SMS_ID,0,SMS_SEND,2,new FunctionArg(numberLength,(byte*)number),
											 new FunctionArg(textLength,(byte*)text));
}

bool SMSShieldClass::isNewSms()
{
	return isItNewSms;
}

void SMSShieldClass::send(String number,String text)
{
	int numberLength = number.length();
	int textLength = text.length();

	char cTypeNumber[numberLength+1];
	char cTypeText[textLength+1];

	for (int i = 0; i < numberLength; i++)
	{
		cTypeNumber[i]=number[i];
	}
	cTypeNumber[numberLength]='\0';

	for (int j = 0; j <textLength; j++)
	{
		cTypeText[j]=text[j];
	}
	cTypeText[textLength]='\0';

	send(cTypeNumber,cTypeText);
}

//Number Getter
char * SMSShieldClass::getNumber()
{
	isItNewSms=false;
	return number;
}
//Number Getter
String SMSShieldClass::getNumberAsString()
{
	isItNewSms=false;
	String numberInString (number);
	return numberInString;
}
//SMS Getter
char * SMSShieldClass::getSms()
{
	isItNewSms=false;
	return text;
}
//SMS Getter
String SMSShieldClass::getSmsAsString()
{
	isItNewSms=false;
	String smsInString(text);
	return smsInString;
}

//SMS Input Data Processing
void SMSShieldClass::processData()
  {
  	//Checking Function-ID
	byte functionID= getOneSheeldInstance().getFunctionId();
	if(functionID==SMS_GET)
	{
		isItNewSms =true;
		if(text!=0)
		{
			free(text);
		}
		if (number!=0)
		{
			free(number);
		}
		int numberlength=getOneSheeldInstance().getArgumentLength(0);
		number=(char*)malloc(sizeof(char)*(numberlength+1));
		for (int j=0; j<numberlength; j++)
		{
			number[j]=getOneSheeldInstance().getArgumentData(0)[j];
		}
		number[numberlength]='\0';
		int textlength=getOneSheeldInstance().getArgumentLength(1);
		text=(char*)malloc(sizeof(char)*(textlength+1));

		for(int i=0 ;i<textlength;i++)
		{
			text[i]=getOneSheeldInstance().getArgumentData(1)[i];
		}
			text[textlength]='\0';
		//Users Function Invoked
		if(!isInACallback())
		{
			if(isCallBackAssigned)
			{
				enteringACallback();
				(*changeCallBack)(number,text);
				exitingACallback();
			}

			if(usedSetOnWithString)
			{
				enteringACallback();
				(*changeCallBackString)(getNumberAsString(),getSmsAsString());
				exitingACallback();
			}
		}
	}
}
//Users Function Setter
void SMSShieldClass::setOnSmsReceive(void (*userFunction)(char number[] ,char text[]))
{
	changeCallBack=userFunction;
	isCallBackAssigned=true;
}

void SMSShieldClass::setOnSmsReceive(void (*userFunction)(String number ,String text))
{
	changeCallBackString=userFunction;
	usedSetOnWithString=true;
}

#ifdef SMS_SHIELD
//Instantiating Object
SMSShieldClass SMS;
#endif
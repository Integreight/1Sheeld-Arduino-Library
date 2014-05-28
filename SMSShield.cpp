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
 SMSShieldClass::SMSShieldClass()
  {
  	text=0;
  	number=0;
  	isCallBackAssigned=false;
  }
//SMS Sender
void SMSShieldClass::send(char* number,char* text)
  {
	OneSheeld.sendPacket(SMS_ID,0,SEND_SMS,2,new FunctionArg(strlen(number),(byte*)number),new FunctionArg(strlen(text),(byte*)text));
  }
  //Number Getter
char * SMSShieldClass::getNumber()
{
	return number;
}
//SMS Getter
char * SMSShieldClass::getSms()
{
	return text;
}
//SMS Input Data Processing
void SMSShieldClass::processData()
  {
  	//Checking Function-ID
	byte x= OneSheeld.getFunctionId();
	if(x==GET_SMS)
	{

		if(text!=0)
		{
			free(text);
		}
		if (number!=0)
		{
			free(number);
		}
		int numberlength=OneSheeld.getArgumentLength(0);
		number=(char*)malloc(sizeof(char)*(numberlength+1));
		for (int j=0; j<numberlength; j++)
		{
			number[j]=OneSheeld.getArgumentData(0)[j];
		}
		number[numberlength]='\0';
		int textlength=OneSheeld.getArgumentLength(1);
		text=(char*)malloc(sizeof(char)*(textlength+1));

		for(int i=0 ;i<textlength;i++)
		{
			text[i]=OneSheeld.getArgumentData(1)[i];
		}
			text[textlength]='\0';
		//Users Function Invoked
		if(isCallBackAssigned)
		{
			(*changeCallBack)(number,text);
		}
	}
}
//Users Function Setter
void SMSShieldClass::setOnSmsReceive(void (*userFunction)(char * number ,char * text))
{
	changeCallBack=userFunction;
	isCallBackAssigned=true;
}


//Instantiating Object
SMSShieldClass SMS;
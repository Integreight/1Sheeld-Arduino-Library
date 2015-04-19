/*

  Project:       1Sheeld Library 
  File:          SMSShield.h
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/

#ifndef SMSShield_h
#define SMSShield_h

#include "ShieldParent.h"

//Outputs Functions ID's
#define SMS_SEND 0x01

//Input Functions ID's  
#define SMS_GET  0x01

class SMSShieldClass : public ShieldParent
{
public:
	//Constructor
	SMSShieldClass();
	//Sender
	void send(const char* ,const char*);
	void send(String , String );
	bool isNewSms();
	//Getter
	char * getSms();
	String getSmsAsString();
	char * getNumber();
	String getNumberAsString();
	//setOnChange for Users Function
	void setOnSmsReceive(void (*)(char [],char []));
	void setOnSmsReceive(void (*)(String ,String ));

private:
	//Reserve Variable
	char * text;
	char * number;
	//Boolean For the setOnChange Function
	bool isCallBackAssigned;
	//Boolean to check if new SMS arrived
	bool isItNewSms;
	//Boolean for setOnSmsString
	bool usedSetOnWithString;
	//Process Input Data 
	void processData();
	void (*changeCallBack)(char [],char []);
	void (*changeCallBackString)(String ,String);
};

//Extern Object
extern SMSShieldClass SMS;
#endif
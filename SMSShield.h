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

//Input Functions ID's
#define SEND_SMS 0x01  
#define GET_SMS 0x01


class SMSShieldClass 
{
public:
	//Constructor
	SMSShieldClass();
	//Sender
	void send(char* ,char*);
	//Getter
	char * getSms();
	char * getNumber();
	//setOnChange for Users Function
	void setOnSmsReceive(void (*)(char*,char*));
private:
	//Reserve Variable
	char * text;
	char * number;
	//Boolean For the setOnChange Function
	bool isCallBackAssigned;
	//Process Input Data 
	void processData();
	void (*changeCallBack)(char*,char*);
	
	
	friend class OneSheeldClass ;
};

//Extern Object
extern SMSShieldClass SMS;
#endif
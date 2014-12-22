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

//Outputs Functions ID's
#define SMS_SEND 0x01
#define SMS_SELECT_SHIELD 0x02
#define SMS_UNSELECT_SHIELD 0x03 
//Input Functions ID's 
#define SMS_GET  0x01
#define SMS_CHECK_SELECTED	0x02


class SMSShieldClass 
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
	//Selection
	void select();
	void unselect();
	//setOnChange for Users Function
	void setOnSmsReceive(void (*)(char*,char*));
	void setOnSmsReceive(void (*)(String ,String ));
	void setOnSelected(void (*)(void));

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
	void (*changeCallBack)(char*,char*);
	void (*changeCallBackString)(String ,String);
	void (*selectedCallBack)(void);	
	
	friend class OneSheeldClass ;
};

//Extern Object
extern SMSShieldClass SMS;
#endif
/*

  Project:       1Sheeld Library 
  File:          PhoneShield.h
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/

#ifndef PhoneShield_h
#define PhoneShield_h


//Output Function ID
#define PHONE_CALL 0x01
#define PHONE_SELECT_SHIELD	0xFE
#define PHONE_UNSELECT_SHIELD	0xFD
//Input Function ID's
#define PHONE_IS_RINGING 0x01
#define PHONE_GET_NUMBER 0x02
#define PHONE_CHECK_SELECTED 0xFF


class PhoneShieldClass 
{
public:
	//Constructor 
	PhoneShieldClass();
	//Setter
	void call(const char* );
	void call(String);
	//Checker
	bool isRinging();
	//Getter
	char * getNumber();
	String getNumberAsString();
	//Selection
	void select();
	void unselect();
	//setOnChange for Users Function
	void setOnCallStatusChange(void (*)(bool ,char *));
	void setOnCallStatusChange(void (*)(bool , String));
	void setOnSelected(void(*)(void));
private:
	//Reserve Variable
	byte value ;
	char * number;
	//Boolean For the setOnChange Function
	bool isCallBackAssigned;
	bool usedSetOnString;
	//Process Input Data 
	void processData();
	void (*changeCallBack)(bool ,char *);
	void (*changeCallBackString)(bool , String);
	void (*selectedCallBack)(void);
	
	friend class OneSheeldClass ;
};

//Extern Object
extern PhoneShieldClass Phone;
#endif
/*

  Project:       1Sheeld Library 
  File:          PushButtonShield.h
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/

#ifndef PushButtonShield_h
#define PushButtonShield_h

//Output Function ID's
#define PUSHBUTTON_SELECT_SHIELD	0xFE
#define PUSHBUTTON_UNSELECT_SHIELD	0xFD
//Input Function ID
#define PUSHBUTTON_VALUE 0x01
#define PUSHBUTTON_CHECK_SELECTED	0xFF


class PushButtonShield
{
public:
	//Constructor 
	PushButtonShield();
	//Checker
	bool isPressed();
	//Selection
	void select();
	void unselect();
	//setOnChange for Users Function
	void setOnButtonStatusChange(void (*userFunction)(bool ));
	void setOnSelected(void (*)(void));
public:
	//Reserve Variable
	byte value;
	//Boolean For the setOnChange Function
	bool isCallBackAssigned;
	//Process Input Data 
	void processData();
	void (*changeCallBack)(bool);
	void (*selectedCallBack)(void);

	friend class OneSheeldClass;
	
};

//Extern Object
extern PushButtonShield PushButton;
#endif
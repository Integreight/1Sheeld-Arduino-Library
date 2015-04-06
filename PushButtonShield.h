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

#include "ShieldParent.h"

//Input Function ID
#define PUSHBUTTON_VALUE 0x01

class PushButtonShield : public ShieldParent
{
public:
	//Constructor 
	PushButtonShield();
	//Checker
	bool isPressed();
	//setOnChange for Users Function
	void setOnButtonStatusChange(void (*userFunction)(bool ));

private:
	//Reserve Variable
	byte value;
	//Boolean For the setOnChange Function
	bool isCallBackAssigned;
	//Process Input Data 
	void processData();
	void (*changeCallBack)(bool);	
};

//Extern Object
extern PushButtonShield PushButton;
#endif
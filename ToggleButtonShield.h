/*

  Project:       1Sheeld Library 
  File:          ToggleButtonShield.h
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/

#ifndef ToggleButtonShield_h
#define ToggleButtonShield_h

#include "ShieldParent.h"

//Input Function ID
#define TOGGLEBUTTON_VALUE 0x01

class ToggleButtonShield : public ShieldParent
{
public:
	//Constructor
	ToggleButtonShield();
	//Checker
	bool getStatus();
	//setOnChange for Users Function
	void setOnButtonStatusChange(void (*userFunction)(bool));
	
private:
	//Reserve Variable
	byte value;
	//Boolean for the setOnChange Function
	bool isCallBackAssigned;
	//Process Input Data
	void processData();
	void (*changeCallBack)(bool);
};

//Extern Object
extern ToggleButtonShield ToggleButton;
#endif
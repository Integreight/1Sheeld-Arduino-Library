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

//Input Function ID
#define TOGGLEBUTTON_VALUE 0x01
#define TOGGLEBUTTON_CHECK_SELECTED	0xFF
//Output Function ID's
#define TOGGLEBUTTON_SELECT_SHIELD	0xFE
#define TOGGLEBUTTON_UNSELECT_SHIELD	0xFD


class ToggleButtonShield
{
public:
	//Constructor
	ToggleButtonShield();
	//Checker
	bool getStatus();
	//Selection
	void select();
	void unselect();
	//setOnChange for Users Function
	void setOnButtonStatusChange(void (*userFunction)(bool));
	//set when selected
	void setOnSelected(void (*)(void));
private:
	//Reserve Variable
	byte value;
	//Boolean for the setOnChange Function
	bool isCallBackAssigned;
	//Process Input Data
	void processData();
	void (*changeCallBack)(bool);
	void (*selectedCallBack)(void);

	friend class OneSheeldClass;
};

//Extern Object
extern ToggleButtonShield ToggleButton;
#endif
/*

  Project:       1Sheeld Library 
  File:          KeypadShield.h
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/

#ifndef KeypadShield_h
#define KeypadShield_h

//Output Function ID
#define KEYPAD_SELECT_SHIELD	0xFE
#define KEYPAD_UNSELECT_SHIELD	0xFD
//Input Function ID 
#define KEYPAD_VALUE 0x01
#define KEYPAD_CHECK_SELECTED	0xFF

class KeypadShieldClass 
{
public:
	//Constructor
	KeypadShieldClass();
	//Checkers
	bool isRowPressed(byte x);
	bool isColumnPressed(byte x);
	bool isAnyRowPressed();
	bool isAnyColumnPressed();
	//Selection
	void select();
	void unselect();
	//setOnChange for Users Function
	void setOnButtonChange(void (*)(byte ,byte));
	void setOnSelected(void (*)(void));
private:
	//Reserve Variables
	byte  row;
	byte col;
	//Boolean For setOnChange Function
	bool isCallbackAssigned;
	//Process Input Data  
	void processData();
	void (*buttonChangeCallback)(byte , byte);
 	void (*selectedCallBack)(void);
	
friend class OneSheeldClass;
};

//Extern Object
extern KeypadShieldClass Keypad;

#endif
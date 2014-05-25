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

//Input Function ID 
#define DATA_IN 0x01


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
	//setOnChange for Users Function
	void setOnButtonChange(void (*)(byte ,byte));

private:
	//Reserve Variables
	byte  row;
	byte col;
	//Boolean For setOnChange Function
	bool isCallbackAssigned;
	//Process Input Data  
	void processData();
	void (*buttonChangeCallback)(byte , byte);
 
	
friend class OneSheeldClass;
};

//Extern Object
extern KeypadShieldClass Keypad;

#endif
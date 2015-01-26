/*

  Project:       1Sheeld Library 
  File:          KeyboardShield.h
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/

#ifndef Keyboard_h
#define Keyboard_h

#include "ShieldParent.h"

//Input Function ID 
#define KEYBOARD_GET_CHAR	0x01

class KeyboardShield : public ShieldParent
{
public:
	//Constructor 
	KeyboardShield();
	//Getter 
	char getCharacter();
	//setOnChange Function for User Function
	void setOnButtonChange(void (*)(char));

private:
	//Reserve Variable
	char character;
	//Boolean for the setOnChange Function
	bool isCallBackAssigned;
	//Process Input Data  
	void processData();
	void (*buttonChangeCallBack)(char);
};

//Extern Object
extern KeyboardShield AsciiKeyboard;
#endif


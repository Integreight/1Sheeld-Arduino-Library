/*

  Project:       1Sheeld Library 
  File:          KeyboardShield.h
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/

#ifndef KEYBOARD_H_
#define KEYBOARD_H_

//Input Function ID 
#define GET_CHAR	0x01


class KeyboardShield
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
	
	friend class OneSheeldClass ;


};

//Extern Object
extern KeyboardShield AsciiKeyboard;
#endif


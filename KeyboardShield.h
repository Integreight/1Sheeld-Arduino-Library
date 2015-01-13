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

//Output Function ID
#define KEYBPARD_SELECT_SHIELD	0xFE
#define KEYBPARD_UNSELECT_SHIELD	0xFD  
//Input Function ID 
#define KEYBOARD_GET_CHAR	0x01
#define KEYBOARD_CHECK_SELECTED	0xFF


class KeyboardShield
{
public:
	//Constructor 
	KeyboardShield();
	//Getter 
	char getCharacter();
	//Selection
	void select();
	void unselect();
	//setOnChange Function for User Function
	void setOnButtonChange(void (*)(char));
	void setOnSelected(void (*)(void));
private:
	//Reserve Variable
	char character;
	//Boolean for the setOnChange Function
	bool isCallBackAssigned;
	//Process Input Data  
	void processData();
	void (*buttonChangeCallBack)(char);
	void (*selectedCallBack)(void);
	
	friend class OneSheeldClass ;


};

//Extern Object
extern KeyboardShield AsciiKeyboard;
#endif


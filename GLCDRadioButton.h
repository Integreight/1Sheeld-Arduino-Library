/*

  Project:       1Sheeld Library 
  File:          GLCDRadioButton.h
                 
  Version:       7.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2015.7

*/

#ifndef GLCDRadioButton_h
#define GLCDRadioButton_h

#define GLCD_RADIO_BUTTON_TYPE			0x09
#define GLCD_RADIO_BUTTON_SET_TEXT		0x03
#define GLCD_RADIO_BUTTON_SET_SIZE		0x04
#define GLCD_RADIO_BUTTON_SET_GROUP		0x05
#define GLCD_RADIO_BUTTON_SELECT		0x06

#include "ShapeClass.h"

class GLCDRadioButton : public ShapeClass
{
public:
	GLCDRadioButton(int , int , char *);
	GLCDRadioButton(int , int , char * , int );
	void setText(char *);
	void setSize(byte );
	void setGroup(int );
	// bool isSelected(); 
	void select();
	void setOnChange(void (*userFunction)(byte));
private:
	void draw();
	char * dataString;
	int groupNumber;
	bool sendAsGroup;
	bool isCallBackAssigned;
	// byte value;
	void (*onChangeCallback)(byte); 
};

#endif
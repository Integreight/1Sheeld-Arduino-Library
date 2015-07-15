/*

  Project:       1Sheeld Library 
  File:          GLCDCheckBox.h
                 
  Version:       7.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2015.7

*/

#ifndef GLCDCheckBox_h
#define GLCDCheckBox_h

#define GLCD_CHECK_BOX_TYPE				0x0A
#define GLCD_CHECK_BOX_SET_TEXT			0x03
#define GLCD_CHECK_BOX_SET_SIZE			0x04
#define GLCD_CHECK_BOX_SELECT			0x05


#include "ShapeClass.h"

class GLCDCheckBox : public ShapeClass
{
public:
	GLCDCheckBox(int , int , char *);
	void setText(char *);
	void setSize(byte );
	// bool isSelected(); 
	void select();
	void setOnChange(void (*userFunction)(byte));
private:
	void draw();
	char * dataString;
	// byte value;
	bool isCallBackAssigned; 
	void (*onChangeCallback)(byte);
};

#endif
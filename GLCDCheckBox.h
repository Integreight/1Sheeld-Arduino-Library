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
#define GLCD_CHECK_BOX_UNSELECT			0x06


#include "ShapeClass.h"

class GLCDCheckBox : public ShapeClass
{
friend class GLCDShield;
public:
	GLCDCheckBox(int , int , char *);
	void setText(char *);
	void setSize(byte );
	void select();
	void unselect();
	void setOnChange(void(*)(byte));
private:
	void draw();
	char * dataString;
	bool isCallbackAssigned;
	byte value;
	void (*onChangeCallback)(byte);
};

#endif
/*

  Project:       1Sheeld Library 
  File:          GLCDButton.h
                 
  Version:       7.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2015.7

*/

#ifndef GLCDButton_h
#define GLCDButton_h

#define GLCD_BUTTON_TYPE					0x08
#define GLCD_BUTTON_TEXT					0x03
#define GLCD_BUTTON_DIMENSIONS				0x04
#define GLCD_BUTTON_STYLE					0x05

#define GLCD_BUTTON_VALUE					0x01

#define STYLE_2D							0x00
#define STYLE_3D							0x01

#include "ShapeClass.h"

class GLCDButton : public ShapeClass
{
friend class GLCDShield;
public:
	GLCDButton(int , int , int ,int , const char * );
	GLCDButton(int , int , int ,int);
	bool isPressed();
	void setText(const char *);
	void setStyle(byte );
	void setDimensions(int,int);
	void setOnChange(void(*)(bool));
	~GLCDButton();
private:
	void draw();
	int width; 
	int height;
	int dataStringLength;
	char * dataString;
	bool dataMalloced;
	bool value;
	bool buttonHasName;
	bool isCallBackAssigned;
	void (*onChangeCallback)(bool);
};

#endif
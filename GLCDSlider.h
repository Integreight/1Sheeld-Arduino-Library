/*

  Project:       1Sheeld Library 
  File:          GLCDSlider.h
                 
  Version:       7.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2015.7

*/

#ifndef GLCDSlider_h
#define GLCDSlider_h

#define GLCD_SLIDER_TYPE				0x0B
#define GLCD_SLIDER_RANGE				0x03
#define GLCD_SLIDER_VALUE				0x04
#define GLCD_SLIDER_DIMENSIONS			0x05

#include "ShapeClass.h"

class GLCDSlider : public ShapeClass
{
friend class GLCDShield;
public:
	GLCDSlider(int , int , int ,int );
	void setRange(int , int);
	void setValue(int );
	int getValue();
	void setDimensions(int ,int);
	void setOnChange(void (*)(int));
private:
	void draw();
	int width;
	int height;
	int value;
	bool isCallbackAssigned;
	void (*onChangeCallback)(int);
};

#endif
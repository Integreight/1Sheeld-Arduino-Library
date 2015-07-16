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

#include "InteractiveShapeClass.h"

class GLCDSlider : public InteractiveShapeClass
{
public:
	GLCDSlider(int , int , int ,int );
	void setRange(int , int);
	void setValue(int );
	void setDimensions(int ,int);
private:
	void draw();
	int width;
	int height;
};

#endif
/*

  Project:       1Sheeld Library 
  File:          GLCDProgressBar.h
                 
  Version:       7.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2015.7

*/

#ifndef GLCDProgressBar_h
#define GLCDProgressBar_h

#define GLCD_PROGRESS_BAR_TYPE			0x06
#define GLCD_PROGRESS_BAR_RANGE			0x03
#define GLCD_PROGRESS_BAR_VALUE			0x04
#define GLCD_PROGRESS_BAR_DIMENSIONS	0x05

#include "ShapeClass.h"

class GLCDProgressBar : public ShapeClass
{
public:
	GLCDProgressBar(int , int , int ,int );
	void setRange(int , int);
	void setValue(int );
	void setDimensions(int,int);
private:
	void draw();
	int width; 
	int height; 
};

#endif
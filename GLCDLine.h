/*

  Project:       1Sheeld Library 
  File:          GLCDLine.h
                 
  Version:       7.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2015.7

*/

#ifndef GLCDLine_h
#define GLCDLine_h

#define GLCD_LINE_TYPE				  0x03
#define GLCD_LINE_COORDINATES		0x03


#include "ShapeClass.h"

class GLCDLine : public ShapeClass
{
public:
	GLCDLine(int , int , int ,int );
	void setCoordinates(int , int ,int, int);
private:
	void draw();
	int x2Position; 
	int y2Position; 
};

#endif
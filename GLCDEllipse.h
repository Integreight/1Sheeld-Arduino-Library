/*

  Project:       1Sheeld Library 
  File:          GLCDEllipse.h
                 
  Version:       7.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2015.7

*/

#ifndef GLCDEllipse_h
#define GLCDEllipse_h

#define GLCD_ELLIPSE_TYPE			0x04
#define GLCD_ELLIPSE_RADIUS			0x03
#define GLCD_ELLIPSE_FILL			0x04


#include "ShapeClass.h"

class GLCDEllipse : public ShapeClass
{
public:
	GLCDEllipse(int , int , int ,int );
	void setRadius(int ,int);
	void setFill(bool );
private:
	void draw();
	int radius1; 
	int radius2; 
};

#endif
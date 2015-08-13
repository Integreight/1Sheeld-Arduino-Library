/*

  Project:       1Sheeld Library 
  File:          GLCDRectangle.h
                 
  Version:       7.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2015.7

*/

#ifndef GLCDRectangle_h
#define GLCDRectangle_h

#define GLCD_RECTANGLE_TYPE			0x02
#define GLCD_RECTANGLE_RADIUS		0x03
#define GLCD_RECTANLGE_FILL			0x04
#define GLCD_RECTANGLE_DIMENSIONS	0x05

#include "ShapeClass.h"

class GLCDRectangle : public ShapeClass
{
public:
	GLCDRectangle(int , int , int , int , int =0);
	void setRadius(int);
	void setFill(bool );
	void setDimensions(int,int);
private:
	void draw();
	int width; 
	int height; 
	int radius;
};

#endif
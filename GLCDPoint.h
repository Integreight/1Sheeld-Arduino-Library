/*

  Project:       1Sheeld Library 
  File:          GLCDPoint.h
                 
  Version:       7.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2015.7

*/

#ifndef GLCDPoint_h
#define GLCDPoint_h

#define GLCD_POINT_TYPE	0x01

#include "ShapeClass.h"

class GLCDPoint : public ShapeClass
{
public:
	GLCDPoint(int x , int y): ShapeClass(GLCD_POINT_TYPE,x,y){};
private:
	void draw();
};

#endif
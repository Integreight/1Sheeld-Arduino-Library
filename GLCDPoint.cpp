/*

  Project:       1Sheeld Library 
  File:          GLCDPoint.h
                 
  Version:       7.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2015.7

*/
#define FROM_ONESHEELD_LIBRARY
#include "OneSheeld.h"
#include "GLCDPoint.h"


void GLCDPoint::draw()
{
	byte xPositionArray[2] ;
  	xPositionArray[1] = (xposition >> 8) & 0xFF;
  	xPositionArray[0] = xposition & 0xFF;

  	byte yPositionArray[2] ;
  	yPositionArray[1] = (yposition >> 8) & 0xFF;
  	yPositionArray[0] = yposition & 0xFF;

  	byte shapeIdArray[2] ;
  	shapeIdArray[1] = (shapeID >> 8) & 0xFF;
  	shapeIdArray[0] = shapeID & 0xFF;

    byte functionId = SHAPE_DRAW;
	OneSheeld.sendShieldFrame(GLCD_ID,0,GLCD_POINT_TYPE,4,new FunctionArg(1,&functionId),new FunctionArg(2,shapeIdArray)
																			 ,new FunctionArg(2,xPositionArray)
																			 ,new FunctionArg(2,yPositionArray));
} 
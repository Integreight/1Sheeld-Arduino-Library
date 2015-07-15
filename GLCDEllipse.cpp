/*

  Project:       1Sheeld Library 
  File:          GLCDEllipse.h
                 
  Version:       7.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2015.7

*/
#define FROM_ONESHEELD_LIBRARY
#include "OneSheeld.h"
#include "GLCDEllipse.h"


GLCDEllipse::GLCDEllipse(int x , int y, int _radius1 , int _radius2): ShapeClass(GLCD_ELLIPSE_TYPE,x,y)
{
  radius1 = _radius1;
  radius2 = _radius2;
}


void GLCDEllipse::draw()
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

    byte radius1Array[2] ;
    radius1Array[1] = (radius1 >> 8) & 0xFF;
    radius1Array[0] = radius1 & 0xFF;

    byte radius2Array[2] ;
    radius2Array[1] = (radius2 >> 8) & 0xFF;
    radius2Array[0] = radius2 & 0xFF;

    byte functionId = SHAPE_DRAW;

	OneSheeld.sendPacket(GLCD_ID,0,GLCD_ELLIPSE_TYPE,6,new FunctionArg(1,&functionId),new FunctionArg(2,shapeIdArray)
																			                                          ,new FunctionArg(2,xPositionArray)
																			                                          ,new FunctionArg(2,yPositionArray)
                                                                                ,new FunctionArg(2,radius1Array)
                                                                                ,new FunctionArg(2,radius2Array));
}

void GLCDEllipse::setRadius(int radius)
{
    byte radiusArray[2] ;
    radiusArray[1] = (radius >> 8) & 0xFF;
    radiusArray[0] = radius & 0xFF;

    byte shapeIdArray[2] ;
    shapeIdArray[1] = (shapeID >> 8) & 0xFF;
    shapeIdArray[0] = shapeID & 0xFF;

    byte functionId = GLCD_ELLIPSE_RADIUS;

  OneSheeld.sendPacket(GLCD_ID,0,GLCD_ELLIPSE_TYPE,3,new FunctionArg(1,&functionId),new FunctionArg(2,shapeIdArray)
                                                                               ,new FunctionArg(2,radiusArray));
}

void GLCDEllipse::setFill(byte fillingType)
{

    byte shapeIdArray[2] ;
    shapeIdArray[1] = (shapeID >> 8) & 0xFF;
    shapeIdArray[0] = shapeID & 0xFF;

    byte functionId = GLCD_ELLIPSE_FILL; 

  OneSheeld.sendPacket(GLCD_ID,0,GLCD_ELLIPSE_TYPE,3,new FunctionArg(1,&functionId),new FunctionArg(2,shapeIdArray)
                                                                               ,new FunctionArg(2,&fillingType));
}  


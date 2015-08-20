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

    byte radiusArray1[2] ;
    radiusArray1[1] = (radius1 >> 8) & 0xFF;
    radiusArray1[0] = radius1 & 0xFF;

    byte radiusArray2[2] ;
    radiusArray2[1] = (radius2 >> 8) & 0xFF;
    radiusArray2[0] = radius2 & 0xFF;

    byte functionId = SHAPE_DRAW;

	OneSheeld.sendShieldFrame(GLCD_ID,0,GLCD_ELLIPSE_TYPE,6,new FunctionArg(1,&functionId),new FunctionArg(2,shapeIdArray)
																			                                          ,new FunctionArg(2,xPositionArray)
																			                                          ,new FunctionArg(2,yPositionArray)
                                                                                ,new FunctionArg(2,radiusArray1)
                                                                                ,new FunctionArg(2,radiusArray2));
}

void GLCDEllipse::setRadius(int radius1 , int radius2)
{
    byte radiusArray1[2] ;
    radiusArray1[1] = (radius1 >> 8) & 0xFF;
    radiusArray1[0] = radius1 & 0xFF;


    byte radiusArray2[2] ;
    radiusArray2[1] = (radius2 >> 8) & 0xFF;
    radiusArray2[0] = radius2 & 0xFF;

    byte shapeIdArray[2] ;
    shapeIdArray[1] = (shapeID >> 8) & 0xFF;
    shapeIdArray[0] = shapeID & 0xFF;

    byte functionId = GLCD_ELLIPSE_RADIUS;

  OneSheeld.sendShieldFrame(GLCD_ID,0,GLCD_ELLIPSE_TYPE,4,new FunctionArg(1,&functionId),new FunctionArg(2,shapeIdArray)
                                                                               ,new FunctionArg(2,radiusArray1)
                                                                               ,new FunctionArg(2,radiusArray2));
}

void GLCDEllipse::setFill(bool fillValue)
{

    byte shapeIdArray[2] ;
    shapeIdArray[1] = (shapeID >> 8) & 0xFF;
    shapeIdArray[0] = shapeID & 0xFF;

    byte functionId = GLCD_ELLIPSE_FILL; 

  OneSheeld.sendShieldFrame(GLCD_ID,0,GLCD_ELLIPSE_TYPE,3,new FunctionArg(1,&functionId),new FunctionArg(2,shapeIdArray)
                                                                               ,new FunctionArg(1,(byte *)&fillValue));
}  


/*

  Project:       1Sheeld Library 
  File:          GLCDLine.h
                 
  Version:       7.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2015.7

*/
#define FROM_ONESHEELD_LIBRARY
#include "OneSheeld.h"
#include "GLCDLine.h"


GLCDLine::GLCDLine(int x, int y, int _x2Position , int _y2Position): ShapeClass(GLCD_LINE_TYPE,x,y)
{
  x2Position = _x2Position;
  y2Position = _y2Position;
}

void GLCDLine::draw()
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

    byte x2PositionArray[2] ;
    x2PositionArray[1] = (x2Position >> 8) & 0xFF;
    x2PositionArray[0] = x2Position & 0xFF;

    byte y2PositionArray[2] ;
    y2PositionArray[1] = (y2Position >> 8) & 0xFF;
    y2PositionArray[0] = y2Position & 0xFF;

    byte functionId = SHAPE_DRAW;

	OneSheeld.sendPacket(GLCD_ID,0,GLCD_LINE_TYPE,6,new FunctionArg(1,&functionId),new FunctionArg(2,shapeIdArray)
																			                                          ,new FunctionArg(2,xPositionArray)
																			                                          ,new FunctionArg(2,yPositionArray)
                                                                                ,new FunctionArg(2,x2PositionArray)
                                                                                ,new FunctionArg(2,y2PositionArray));
}

void GLCDLine::setCoordinates(int xNewCoordinate , int yNewCoordinate)
{
      byte xNewCoordinateArray[2] ;
    xNewCoordinateArray[1] = (xNewCoordinate >> 8) & 0xFF;
    xNewCoordinateArray[0] = xNewCoordinate & 0xFF;

    byte yNewCoordinateArray[2] ;
    yNewCoordinateArray[1] = (yNewCoordinate >> 8) & 0xFF;
    yNewCoordinateArray[0] = yNewCoordinate & 0xFF;

    byte shapeIdArray[2] ;
    shapeIdArray[1] = (shapeID >> 8) & 0xFF;
    shapeIdArray[0] = shapeID & 0xFF;

    byte functionId = GLCD_LINE_COORDINATES;

  OneSheeld.sendPacket(GLCD_ID,0,GLCD_LINE_TYPE,4,new FunctionArg(1,&functionId),new FunctionArg(2,shapeIdArray)
                                                                               ,new FunctionArg(2,xNewCoordinateArray)
                                                                               ,new FunctionArg(2,yNewCoordinateArray));
}


/*

  Project:       1Sheeld Library 
  File:          ShapeClass.h
                 
  Version:       7.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2015.7

*/
#define FROM_ONESHEELD_LIBRARY
#include "OneSheeld.h"
#include "ShapeClass.h"

int ShapeClass::currentShapeId=0;

ShapeClass::ShapeClass(byte _shapeType,int _xPosition, int _yPosition)
{
	shapeType = _shapeType;
	shapeID =currentShapeId++;
	xposition=_xPosition;
	yposition=_yPosition;
  isInteractiveShape=false;
}


void ShapeClass::setVisibility(byte visbilityType)
{
  byte functionId = SHAPE_VISIBILITY;

  byte shapeIdArray[2] ;
    shapeIdArray[1] = (shapeID >> 8) & 0xFF;
    shapeIdArray[0] = shapeID & 0xFF;
	
  OneSheeld.sendShieldFrame(GLCD_ID,0,shapeType,3,new FunctionArg(1,&functionId),new FunctionArg(2,shapeIdArray)
                                                                           ,new FunctionArg(1,&visbilityType));
}

void ShapeClass::setPosition(int xposition , int yposition)
{
  byte functionId = SHAPE_POSITION;

	byte xPositionArray[2] ;
  	xPositionArray[1] = (xposition >> 8) & 0xFF;
  	xPositionArray[0] = xposition & 0xFF;

  	byte yPositionArray[2] ;
  	yPositionArray[1] = (yposition >> 8) & 0xFF;
  	yPositionArray[0] = yposition & 0xFF;  

  byte shapeIdArray[2] ;
    shapeIdArray[1] = (shapeID >> 8) & 0xFF;
    shapeIdArray[0] = shapeID & 0xFF;
  
	OneSheeld.sendShieldFrame(GLCD_ID,0,shapeType,4,new FunctionArg(1,&functionId),new FunctionArg(2,shapeIdArray)
                                                                           ,new FunctionArg(2,xPositionArray)
                                  																				 ,new FunctionArg(2,yPositionArray));
}
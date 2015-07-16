/*

  Project:       1Sheeld Library 
  File:          GLCDButton.cpp
                 
  Version:       7.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2015.7

*/
#define FROM_ONESHEELD_LIBRARY
#include "OneSheeld.h"
#include "GLCDButton.h"


GLCDButton::GLCDButton(int x , int y, int _width , int _height): InteractiveShapeClass(GLCD_BUTTON_TYPE,x,y)
{
  width = _width;
  height = _height;
}

GLCDButton::GLCDButton(int x , int y, int _width , int _height ,char * _dataString = NULL): InteractiveShapeClass(GLCD_BUTTON_TYPE,x,y)
{
  width = _width;
  height = _height;
  dataString = _dataString;
}

// bool GLCDButton::isPressed()
// {
//   return !!value;
// }

void GLCDButton::draw()
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

    byte widthArray[2] ;
    widthArray[1] = (width >> 8) & 0xFF;
    widthArray[0] = width & 0xFF;

    byte heightArray[2] ;
    heightArray[1] = (height >> 8) & 0xFF;
    heightArray[0] = height & 0xFF;

    byte functionId = SHAPE_DRAW;

  	OneSheeld.sendPacket(GLCD_ID,0,GLCD_BUTTON_TYPE,7,new FunctionArg(1,&functionId),new FunctionArg(2,shapeIdArray)
	   																		                                          ,new FunctionArg(2,xPositionArray)
		  																	                                          ,new FunctionArg(2,yPositionArray)
                                                                                  ,new FunctionArg(2,widthArray)
                                                                                  ,new FunctionArg(2,heightArray)
                                                                                  ,new FunctionArg(strlen(dataString),(byte *)dataString));
}

void GLCDButton::setText(char * _dataString)
{
    dataString = _dataString;

    byte shapeIdArray[2] ;
    shapeIdArray[1] = (shapeID >> 8) & 0xFF;
    shapeIdArray[0] = shapeID & 0xFF;

    byte functionId = GLCD_BUTTON_TEXT;

  OneSheeld.sendPacket(GLCD_ID,0,GLCD_BUTTON_TYPE,3,new FunctionArg(1,&functionId),new FunctionArg(2,shapeIdArray)
                                                                             ,new FunctionArg(strlen(dataString),(byte *)dataString));
}

void GLCDButton::setStyle(byte style)
{
    byte shapeIdArray[2] ;
    shapeIdArray[1] = (shapeID >> 8) & 0xFF;
    shapeIdArray[0] = shapeID & 0xFF;

    byte functionId = GLCD_BUTTON_STYLE; 

  OneSheeld.sendPacket(GLCD_ID,0,GLCD_BUTTON_TYPE,3,new FunctionArg(1,&functionId),new FunctionArg(2,shapeIdArray)
                                                                             ,new FunctionArg(1,&style));
}  

void GLCDButton::setDimensions(int xdimension, int ydimension)
{
    byte xdimensionArray[2] ;
    xdimensionArray[1] = (xdimension >> 8) & 0xFF;
    xdimensionArray[0] = xdimension & 0xFF;

    byte ydimensionArray[2] ;
    ydimensionArray[1] = (ydimension >> 8) & 0xFF;
    ydimensionArray[0] = ydimension & 0xFF;

    byte shapeIdArray[2] ;
    shapeIdArray[1] = (shapeID >> 8) & 0xFF;
    shapeIdArray[0] = shapeID & 0xFF;

    byte functionId = GLCD_BUTTON_DIMENSIONS;

    OneSheeld.sendPacket(GLCD_ID,0,GLCD_BUTTON_TYPE,4,new FunctionArg(1,&functionId),new FunctionArg(2,shapeIdArray)
                                                                               ,new FunctionArg(2,xdimensionArray)
                                                                               ,new FunctionArg(2,ydimensionArray));
}  

void GLCDButton::setOnChange(void (*userFunction)(byte))
{
  isCallBackAssigned = true;
  onChangeCallback = userFunction;
}
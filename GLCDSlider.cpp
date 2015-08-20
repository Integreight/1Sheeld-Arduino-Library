/*

  Project:       1Sheeld Library 
  File:          GLCDSlider.cpp
                 
  Version:       7.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2015.7

*/
#define FROM_ONESHEELD_LIBRARY
#include "OneSheeld.h"
#include "GLCDSlider.h"


GLCDSlider::GLCDSlider(int x , int y, int _width, int _height): ShapeClass(GLCD_SLIDER_TYPE,x,y)
{
  width = _width;
  height = _height;
  value=0;
  isCallbackAssigned = false;
  isInteractiveShape = true;
}

void GLCDSlider::draw()
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

  OneSheeld.sendShieldFrame(GLCD_ID,0,GLCD_SLIDER_TYPE,6,new FunctionArg(1,&functionId),new FunctionArg(2,shapeIdArray)
                                                                                ,new FunctionArg(2,xPositionArray)
                                                                                ,new FunctionArg(2,yPositionArray)
                                                                                ,new FunctionArg(2,widthArray)
                                                                                ,new FunctionArg(2,heightArray));
}

int GLCDSlider::getValue()
{
  return value;
}

void GLCDSlider::setRange(int start, int end)
{

       if(start > end)
    {
        int temp = start;
        start = end;
        end =temp;     
    }
    else if ((start==end) || start<0 || end <0)
    {
      start = 0;
      end = 100;
    }

    byte startArray[2] ;
    startArray[1] = (start >> 8) & 0xFF;
    startArray[0] = start & 0xFF;

    byte endArray[2] ;
    endArray[1] = (end >> 8) & 0xFF;
    endArray[0] = end & 0xFF;

    byte shapeIdArray[2] ;
    shapeIdArray[1] = (shapeID >> 8) & 0xFF;
    shapeIdArray[0] = shapeID & 0xFF;

    byte functionId = GLCD_SLIDER_RANGE;

  OneSheeld.sendShieldFrame(GLCD_ID,0,GLCD_SLIDER_TYPE,4,new FunctionArg(1,&functionId),new FunctionArg(2,shapeIdArray)
                                                                                   ,new FunctionArg(2,startArray)
                                                                                   ,new FunctionArg(2,endArray));
}

void GLCDSlider::setValue(int sliderValue)
{
    byte sliderValueArray[2] ;
    sliderValueArray[1] = (sliderValue >> 8) & 0xFF;
    sliderValueArray[0] = sliderValue & 0xFF;

    byte shapeIdArray[2] ;
    shapeIdArray[1] = (shapeID >> 8) & 0xFF;
    shapeIdArray[0] = shapeID & 0xFF;

    byte functionId = GLCD_SLIDER_VALUE; 

  OneSheeld.sendShieldFrame(GLCD_ID,0,GLCD_SLIDER_TYPE,3,new FunctionArg(1,&functionId),new FunctionArg(2,shapeIdArray)
                                                                                   ,new FunctionArg(2,sliderValueArray));
}  

void GLCDSlider::setDimensions(int xdimension, int ydimension)
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

    byte functionId = GLCD_SLIDER_DIMENSIONS;

    OneSheeld.sendShieldFrame(GLCD_ID,0,GLCD_SLIDER_TYPE,4,new FunctionArg(1,&functionId),new FunctionArg(2,shapeIdArray)
                                       ,new FunctionArg(2,xdimensionArray)
                                       ,new FunctionArg(2,ydimensionArray));
}  

void GLCDSlider::setOnChange(void (*userFunction)(int))
{
  isCallbackAssigned = true;
  onChangeCallback = userFunction;
}
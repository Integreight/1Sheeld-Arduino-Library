/*

  Project:       1Sheeld Library 
  File:          GLCDRectangle.h
                 
  Version:       7.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2015.7

*/
#define FROM_ONESHEELD_LIBRARY
#include "OneSheeld.h"
#include "GLCDRectangle.h"



GLCDRectangle::GLCDRectangle(int x , int y, int _width , int _height, int _radius): ShapeClass(GLCD_RECTANGLE_TYPE,x,y)
{
  width = _width;
  height = _height;
  radius = _radius;
}


void GLCDRectangle::draw()
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

    byte radiusArray[2] ;
    radiusArray[1] = (radius >> 8) & 0xFF;
    radiusArray[0] = radius & 0xFF;

    byte functionId = SHAPE_DRAW;

	OneSheeld.sendShieldFrame(GLCD_ID,0,GLCD_RECTANGLE_TYPE,7,new FunctionArg(1,&functionId),new FunctionArg(2,shapeIdArray)
																			                                          ,new FunctionArg(2,xPositionArray)
																			                                          ,new FunctionArg(2,yPositionArray)
                                                                                ,new FunctionArg(2,widthArray)
                                                                                ,new FunctionArg(2,heightArray)
                                                                                ,new FunctionArg(2,radiusArray));
}

void GLCDRectangle::setRadius(int radius)
{
    byte radiusArray[2] ;
    radiusArray[1] = (radius >> 8) & 0xFF;
    radiusArray[0] = radius & 0xFF;

    byte shapeIdArray[2] ;
    shapeIdArray[1] = (shapeID >> 8) & 0xFF;
    shapeIdArray[0] = shapeID & 0xFF;

    byte functionId = GLCD_RECTANGLE_RADIUS;

  OneSheeld.sendShieldFrame(GLCD_ID,0,GLCD_RECTANGLE_TYPE,3,new FunctionArg(1,&functionId),new FunctionArg(2,shapeIdArray)
                                                                               ,new FunctionArg(2,radiusArray));
}

void GLCDRectangle::setFill(bool fillValue)
{

    byte shapeIdArray[2] ;
    shapeIdArray[1] = (shapeID >> 8) & 0xFF;
    shapeIdArray[0] = shapeID & 0xFF;

    byte functionId = GLCD_RECTANLGE_FILL;

  OneSheeld.sendShieldFrame(GLCD_ID,0,GLCD_RECTANGLE_TYPE,3,new FunctionArg(1,&functionId),new FunctionArg(2,shapeIdArray)
                                                                               ,new FunctionArg(1,(byte *)&fillValue));
}  

void GLCDRectangle::setDimensions(int xdimension, int ydimension)
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

    byte functionId = GLCD_RECTANGLE_DIMENSIONS;

    OneSheeld.sendShieldFrame(GLCD_ID,0,GLCD_RECTANGLE_TYPE,4,new FunctionArg(1,&functionId),new FunctionArg(2,shapeIdArray)
                                       ,new FunctionArg(2,xdimensionArray)
                                       ,new FunctionArg(2,ydimensionArray));
}  

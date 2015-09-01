/*

  Project:       1Sheeld Library 
  File:          GLCDAnalogGauge.h
                 
  Version:       7.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2015.7

*/
#define FROM_ONESHEELD_LIBRARY
#include "OneSheeld.h"
#include "GLCDAnalogGauge.h"


GLCDAnalogGauge::GLCDAnalogGauge(int x , int y, int _radius): ShapeClass(GLCD_ANALOG_GAUGE_TYPE,x,y)
{
  radius = _radius;
}

void GLCDAnalogGauge::draw()
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

    byte radiusArray[2] ;
    radiusArray[1] = (radius >> 8) & 0xFF;
    radiusArray[0] = radius & 0xFF;

    byte functionId = SHAPE_DRAW;

  	OneSheeld.sendShieldFrame(GLCD_ID,0,GLCD_ANALOG_GAUGE_TYPE,5,new FunctionArg(1,&functionId),new FunctionArg(2,shapeIdArray)
	   																		                                          ,new FunctionArg(2,xPositionArray)
		  																	                                          ,new FunctionArg(2,yPositionArray)
                                                                                  ,new FunctionArg(2,radiusArray));
}

void GLCDAnalogGauge::setRange(int start, int end)
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

    byte functionId = GLCD_ANALOG_GAUGE_RANGE;

  OneSheeld.sendShieldFrame(GLCD_ID,0,GLCD_ANALOG_GAUGE_TYPE,4,new FunctionArg(1,&functionId),new FunctionArg(2,shapeIdArray)
                                                                                   ,new FunctionArg(2,startArray)
                                                                                   ,new FunctionArg(2,endArray));
}

void GLCDAnalogGauge::setValue(int analogGaugeValue)
{
    byte analogGaugeValueArray[2] ;
    analogGaugeValueArray[1] = (analogGaugeValue >> 8) & 0xFF;
    analogGaugeValueArray[0] = analogGaugeValue & 0xFF;

    byte shapeIdArray[2] ;
    shapeIdArray[1] = (shapeID >> 8) & 0xFF;
    shapeIdArray[0] = shapeID & 0xFF;

    byte functionId = GLCD_ANALOG_GAUGE_VALUE; 

  OneSheeld.sendShieldFrame(GLCD_ID,0,GLCD_ANALOG_GAUGE_TYPE,3,new FunctionArg(1,&functionId),new FunctionArg(2,shapeIdArray)
                                                                                   ,new FunctionArg(2,analogGaugeValueArray));
}  

void GLCDAnalogGauge::setRadius(int radiusValue)
{
    byte radiusValueArray[2] ;
    radiusValueArray[1] = (radiusValue >> 8) & 0xFF;
    radiusValueArray[0] = radiusValue & 0xFF;

    byte shapeIdArray[2] ;
    shapeIdArray[1] = (shapeID >> 8) & 0xFF;
    shapeIdArray[0] = shapeID & 0xFF;

    byte functionId = GLCD_ANALOG_GAUGE_RADIUS;

    OneSheeld.sendShieldFrame(GLCD_ID,0,GLCD_ANALOG_GAUGE_TYPE,3,new FunctionArg(1,&functionId),new FunctionArg(2,shapeIdArray)
                                                                                     ,new FunctionArg(2,radiusValueArray));
}  

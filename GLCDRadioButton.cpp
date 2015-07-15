/*

  Project:       1Sheeld Library 
  File:          GLCDRadioButton.h
                 
  Version:       7.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2015.7

*/
#define FROM_ONESHEELD_LIBRARY
#include "OneSheeld.h"
#include "GLCDRadioButton.h"


GLCDRadioButton::GLCDRadioButton(int x , int y, char * _dataString): ShapeClass(GLCD_RADIO_BUTTON_TYPE,x,y)
{
  dataString = _dataString;
  // value=0;
  isCallBackAssigned= false;
}

GLCDRadioButton::GLCDRadioButton(int x , int y, char * _dataString , int _groupNumber =0): ShapeClass(GLCD_RADIO_BUTTON_TYPE,x,y)
{
  sendAsGroup = true;
  dataString = _dataString;
  groupNumber = _groupNumber;
  // value=0;
}

void GLCDRadioButton::draw()
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

    if(!sendAsGroup)
    {
      OneSheeld.sendPacket(GLCD_ID,0,GLCD_RADIO_BUTTON_TYPE,5,new FunctionArg(1,&functionId),new FunctionArg(2,shapeIdArray)
                                                                                  ,new FunctionArg(2,xPositionArray)
                                                                                  ,new FunctionArg(2,yPositionArray)
                                                                                  ,new FunctionArg(strlen(dataString),(byte *)dataString));  
    }
    else
    {
      byte groupNumberArray[2] ;
      groupNumberArray[1] = (groupNumber >> 8) & 0xFF;
      groupNumberArray[0] = groupNumber & 0xFF;
      
      OneSheeld.sendPacket(GLCD_ID,0,GLCD_RADIO_BUTTON_TYPE,6,new FunctionArg(1,&functionId),new FunctionArg(2,shapeIdArray)
                                                                                  ,new FunctionArg(2,xPositionArray)
                                                                                  ,new FunctionArg(2,yPositionArray)
                                                                                  ,new FunctionArg(strlen(dataString),(byte *)dataString)
                                                                                  ,new FunctionArg(2,groupNumberArray));
      sendAsGroup = false;
    }
  	
}

void GLCDRadioButton::setText(char * dataString)
{
    byte shapeIdArray[2] ;
    shapeIdArray[1] = (shapeID >> 8) & 0xFF;
    shapeIdArray[0] = shapeID & 0xFF;

    byte functionId = GLCD_RADIO_BUTTON_SET_TEXT;

  OneSheeld.sendPacket(GLCD_ID,0,GLCD_RADIO_BUTTON_TYPE,3,new FunctionArg(1,&functionId),new FunctionArg(2,shapeIdArray)
                                                                                   ,new FunctionArg(strlen(dataString),(byte *)dataString));
}


void GLCDRadioButton::setSize(byte size)
{

    byte shapeIdArray[2] ;
    shapeIdArray[1] = (shapeID >> 8) & 0xFF;
    shapeIdArray[0] = shapeID & 0xFF;

    byte functionId = GLCD_RADIO_BUTTON_SET_SIZE; 

  OneSheeld.sendPacket(GLCD_ID,0,GLCD_RADIO_BUTTON_TYPE,3,new FunctionArg(1,&functionId),new FunctionArg(2,shapeIdArray)
                                                                              ,new FunctionArg(1,&size));
}  


void GLCDRadioButton::setGroup(int number)
{

    byte numberArray[2] ;
    numberArray[1] = (number >> 8) & 0xFF;
    numberArray[0] = number & 0xFF;

    byte shapeIdArray[2] ;
    shapeIdArray[1] = (shapeID >> 8) & 0xFF;
    shapeIdArray[0] = shapeID & 0xFF;

    byte functionId = GLCD_RADIO_BUTTON_SET_GROUP;

    OneSheeld.sendPacket(GLCD_ID,0,GLCD_RADIO_BUTTON_TYPE,3,new FunctionArg(1,&functionId),new FunctionArg(2,shapeIdArray)
                                                                                     ,new FunctionArg(2,numberArray));
}  

void GLCDRadioButton::select()
{

    byte shapeIdArray[2] ;
    shapeIdArray[1] = (shapeID >> 8) & 0xFF;
    shapeIdArray[0] = shapeID & 0xFF;

    byte functionId = GLCD_RADIO_BUTTON_SELECT;

    OneSheeld.sendPacket(GLCD_ID,0,GLCD_RADIO_BUTTON_TYPE,2,new FunctionArg(1,&functionId),new FunctionArg(2,shapeIdArray));
} 

// bool GLCDRadioButton::isSelected()
// {

//    return !!value;
// } 


void GLCDRadioButton::setOnChange(void (*userFunction)(byte))
{
  isCallBackAssigned = true;
  onChangeCallback = userFunction;
}
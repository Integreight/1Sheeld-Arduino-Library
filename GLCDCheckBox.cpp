/*

  Project:       1Sheeld Library 
  File:          GLCDCheckBox.cpp
                 
  Version:       7.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2015.7

*/
#define FROM_ONESHEELD_LIBRARY
#include "OneSheeld.h"
#include "GLCDCheckBox.h"


GLCDCheckBox::GLCDCheckBox(int x , int y, char * _dataString): ShapeClass(GLCD_CHECK_BOX_TYPE,x,y)
{
  dataStringLength = strlen(_dataString)+1;
  dataString = NULL;
  dataMalloced=false;
   if(dataStringLength!=0)
  {
    dataString = (char *) malloc(sizeof(char)*(dataStringLength));
    memcpy(dataString,_dataString,dataStringLength);
    dataMalloced=true;
  }
  value = false;
  isCallbackAssigned = false;
  isInteractiveShape = true;
}

void GLCDCheckBox::draw()
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

    OneSheeld.sendShieldFrame(GLCD_ID,0,GLCD_CHECK_BOX_TYPE,5,new FunctionArg(1,&functionId),new FunctionArg(2,shapeIdArray)
                                                                                  ,new FunctionArg(2,xPositionArray)
                                                                                  ,new FunctionArg(2,yPositionArray)
                                                                                  ,new FunctionArg(strlen(dataString),(byte *)dataString));  
  	
}

bool GLCDCheckBox::isSelected()
{
  return value;
}

void GLCDCheckBox::setText(char * dataString)
{
    byte shapeIdArray[2] ;
    shapeIdArray[1] = (shapeID >> 8) & 0xFF;
    shapeIdArray[0] = shapeID & 0xFF;

    byte functionId = GLCD_CHECK_BOX_SET_TEXT;

  OneSheeld.sendShieldFrame(GLCD_ID,0,GLCD_CHECK_BOX_TYPE,3,new FunctionArg(1,&functionId),new FunctionArg(2,shapeIdArray)
                                                                                   ,new FunctionArg(strlen(dataString),(byte *)dataString));
}


void GLCDCheckBox::setSize(byte size)
{

    byte shapeIdArray[2] ;
    shapeIdArray[1] = (shapeID >> 8) & 0xFF;
    shapeIdArray[0] = shapeID & 0xFF;

    byte functionId = GLCD_CHECK_BOX_SET_SIZE; 

  OneSheeld.sendShieldFrame(GLCD_ID,0,GLCD_CHECK_BOX_TYPE,3,new FunctionArg(1,&functionId),new FunctionArg(2,shapeIdArray)
                                                                              ,new FunctionArg(1,&size));
}  

void GLCDCheckBox::select()
{

    byte shapeIdArray[2] ;
    shapeIdArray[1] = (shapeID >> 8) & 0xFF;
    shapeIdArray[0] = shapeID & 0xFF;

    byte functionId = GLCD_CHECK_BOX_SELECT;

    OneSheeld.sendShieldFrame(GLCD_ID,0,GLCD_CHECK_BOX_TYPE,2,new FunctionArg(1,&functionId),new FunctionArg(2,shapeIdArray));
} 

void GLCDCheckBox::deselect()
{

    byte shapeIdArray[2] ;
    shapeIdArray[1] = (shapeID >> 8) & 0xFF;
    shapeIdArray[0] = shapeID & 0xFF;

    byte functionId = GLCD_CHECK_BOX_UNSELECT;

    OneSheeld.sendShieldFrame(GLCD_ID,0,GLCD_CHECK_BOX_TYPE,2,new FunctionArg(1,&functionId),new FunctionArg(2,shapeIdArray));
} 

void GLCDCheckBox::setOnChange(void (*userFunction)(bool))
{
  isCallbackAssigned = true;
  onChangeCallback = userFunction;
}

GLCDCheckBox::~GLCDCheckBox()
{
  if(dataMalloced)
    free(dataString);
}
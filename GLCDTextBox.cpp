/*

  Project:       1Sheeld Library 
  File:          GLCDTextBox.h
                 
  Version:       7.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2015.7

*/
#define FROM_ONESHEELD_LIBRARY
#include "OneSheeld.h"
#include "GLCDTextBox.h"


GLCDTextBox::GLCDTextBox(int x , int y, char * _dataString): ShapeClass(GLCD_TEXTBOX_TYPE,x,y)
{
   dataString = NULL;
  dataStringLength = strlen(_dataString)+1;
  dataMalloced=false;
  if(dataStringLength!=0)
  {
    dataString = (char *) malloc(sizeof(char)*(dataStringLength));
    memcpy(dataString,_dataString,dataStringLength);
    dataMalloced=true;
  }
}

void GLCDTextBox::draw()
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

	OneSheeld.sendShieldFrame(GLCD_ID,0,GLCD_TEXTBOX_TYPE,5,new FunctionArg(1,&functionId),new FunctionArg(2,shapeIdArray)
																			                                          ,new FunctionArg(2,xPositionArray)
																			                                          ,new FunctionArg(2,yPositionArray)
                                                                                ,new FunctionArg(strlen(dataString),(byte *)dataString));
}

void GLCDTextBox::setFont(byte fontType)
{

    byte shapeIdArray[2] ;
    shapeIdArray[1] = (shapeID >> 8) & 0xFF;
    shapeIdArray[0] = shapeID & 0xFF;

    byte functionId = GLCD_TEXTBOX_SET_FONT;

    OneSheeld.sendShieldFrame(GLCD_ID,0,GLCD_TEXTBOX_TYPE,3,new FunctionArg(1,&functionId),new FunctionArg(2,shapeIdArray)
                                                                                  ,new FunctionArg(1,&fontType));
}

void GLCDTextBox::setSize(byte size)
{

    byte shapeIdArray[2] ;
    shapeIdArray[1] = (shapeID >> 8) & 0xFF;
    shapeIdArray[0] = shapeID & 0xFF;

    byte functionId = GLCD_TEXTBOX_SET_SIZE; 

  OneSheeld.sendShieldFrame(GLCD_ID,0,GLCD_TEXTBOX_TYPE,3,new FunctionArg(1,&functionId),new FunctionArg(2,shapeIdArray)
                                                                              ,new FunctionArg(1,&size));
}  

void GLCDTextBox::setText(char * _dataString)
{
    dataString = _dataString;

    byte shapeIdArray[2] ;
    shapeIdArray[1] = (shapeID >> 8) & 0xFF;
    shapeIdArray[0] = shapeID & 0xFF;

    byte functionId = GLCD_TEXTBOX_TEXT;

  OneSheeld.sendShieldFrame(GLCD_ID,0,GLCD_TEXTBOX_TYPE,3,new FunctionArg(1,&functionId),new FunctionArg(2,shapeIdArray)
                                                                             ,new FunctionArg(strlen(dataString),(byte *)dataString));
}

GLCDTextBox::~GLCDTextBox()
{
  if(dataMalloced)
    free(dataString);
}
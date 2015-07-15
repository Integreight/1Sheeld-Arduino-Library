/*

  Project:       1Sheeld Library 
  File:          InteracticeShapeClass.cpp
                 
  Version:       7.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2015.7

*/
#define FROM_ONESHEELD_LIBRARY
#include "OneSheeld.h"
#include "InteractiveShapeClass.h"


InteractiveShapeClass::InteractiveShapeClass(byte shapeType , int x , int y) : ShapeClass(shapeType,x,y)
{
  isCallBackAssigned = false;
}

void InteractiveShapeClass::setOnChange(void (*userFunction)(byte data))
{
  isCallBackAssigned = true;
  onChangeCallback = userFunction;
}


/*

  Project:       1Sheeld Library 
  File:          KeypadShield.cpp
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/

#include "OneSheeld.h"
#include "KeypadShield.h"



//Class Constructor
KeypadShieldClass::KeypadShieldClass()
{
  row=0;
  col=0;
  isCallbackAssigned=false;
}
//Row Checker 
bool KeypadShieldClass::isRowPressed(byte x)
{
  if(x>7)return false;
return !!(row&(1<<x));
}
//Column Checker
bool KeypadShieldClass::isColumnPressed(byte x)
{
  if(x>7)return false;
return !!(col&(1<<x));
}

//AnyRow Checker
bool KeypadShieldClass::isAnyRowPressed()
{
return !!row;
}
//AnyColumn Checker
bool KeypadShieldClass::isAnyColumnPressed()
{
return !!col;
}

void KeypadShieldClass::select()
{
  OneSheeld.sendPacket(KEYPAD_SHIELD_ID,0,KEYPAD_SELECT_SHIELD,0);
}

void KeypadShieldClass::unselect()
{
  OneSheeld.sendPacket(KEYPAD_SHIELD_ID,0,KEYPAD_UNSELECT_SHIELD,0);
}

//Keypad Input Data Processing
void KeypadShieldClass::processData()
{
  //Checking Function-ID
  byte functionId=OneSheeld.getFunctionId();
  if (functionId==KEYPAD_VALUE)
   { 
     row=OneSheeld.getArgumentData(0)[0];
     col=OneSheeld.getArgumentData(1)[0];
     //Users Function Invoked
     if (isCallbackAssigned)
     (*buttonChangeCallback)(row,col);
   }
   else if(functionId == KEYPAD_CHECK_SELECTED)
   {
      (*selectedCallBack)();
   }
   
}

//Users Function Setter 
void KeypadShieldClass::setOnButtonChange(void (*userFunction)(byte row ,byte column))
{
  buttonChangeCallback=userFunction;
  isCallbackAssigned=true;
}

void KeypadShieldClass::setOnSelected(void (*userFunction)(void))
{
  selectedCallBack=userFunction;
}

//Instatntiating Object
KeypadShieldClass Keypad;


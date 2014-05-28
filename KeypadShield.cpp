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
//Keypad Input Data Processing
void KeypadShieldClass::processData()
{
  //Checking Function-ID
  byte function_Number=OneSheeld.getFunctionId();
  if (function_Number==DATA_IN)
   { 
     row=OneSheeld.getArgumentData(0)[0];
     col=OneSheeld.getArgumentData(1)[0];
     //Users Function Invoked
     if (isCallbackAssigned)
     (*buttonChangeCallback)(row,col);
   }
   
}

//Users Function Setter 
void KeypadShieldClass::setOnButtonChange(void (*userFunction)(byte row ,byte column))
{
  buttonChangeCallback=userFunction;
  isCallbackAssigned=true;
}

//Instatntiating Object
KeypadShieldClass Keypad;


#include "OneSheeld.h"
#include "KeypadShield.h"




KeypadShieldClass::KeypadShieldClass()
{
  row=0;
  col=0;
  isCallbackAssigned=false;
}

bool KeypadShieldClass::isRowPressed(byte x)
{
  if(x>7)return false;
return !!(row&(1<<x));
}

bool KeypadShieldClass::isAnyRowPressed()
{
return !!row;
}

bool KeypadShieldClass::isAnyColumnPressed()
{
return !!col;
}

bool KeypadShieldClass::isColumnPressed(byte x)
{
  if(x>7)return false;
return !!(col&(1<<x));
}

void KeypadShieldClass::processData()
{
  byte function_Number=OneSheeld.getFunctionId();
  if (function_Number==DATA_IN)
   { 
     row=OneSheeld.getArgumentData(0)[0];
     col=OneSheeld.getArgumentData(1)[0];
     if (isCallbackAssigned)
     (*buttonChangeCallback)();
   }
   
}


void KeypadShieldClass::setOnButtonChange(void (*userFunction)())
{
  buttonChangeCallback=userFunction;
  isCallbackAssigned=true;
}

KeypadShieldClass Keypad;


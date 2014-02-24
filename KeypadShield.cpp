#include "OneSheeld.h"
#include "KeypadShield.h"
#include "HardwareSerial.h"




KeypadShieldClass::KeypadShieldClass()
{
  row=0;
  col=0;
  isCallbackAssigned=false;
}

bool KeypadShieldClass::isRowPressed(byte x)
{
  if(x>3)return false;
return !!(row&(1<<x));
}

bool KeypadShieldClass::isColumnPressed(byte x)
{
  if(x>3)return false;
return !!(col&(1<<x));
}

void KeypadShieldClass::processData()
{
  byte function_Number=OneSheeld.getFunctionId();
  if (function_Number==DATA_IN)
   { 
     row=OneSheeld.getArgumentData(0)[0]&(0x0f);
     col=(OneSheeld.getArgumentData(0)[0]&(0xf0))>>4;
   }
   if (isCallbackAssigned)
   (*buttonChangeCallback)(row,col);
}


void KeypadShieldClass::setOnButtonChange(void (*userFunction)(int,int))
{
  buttonChangeCallback=userFunction;
  isCallbackAssigned=true;
}

KeypadShieldClass Keypad;


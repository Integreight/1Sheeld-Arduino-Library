#include "OneSheeld.h"
#include "KeypadShield.h"
#include "HardwareSerial.h"




KeypadShieldClass::KeypadShieldClass()
{
  row=0xff;
  col=0xff;
  isCallbackAssigned=false;
}

void KeypadShieldClass::init()
{}

int KeypadShieldClass::getRow()
{

return row;
}
int KeypadShieldClass::getCol()
{

return col;
}

int KeypadShieldClass::getButton()
{

return 1;
}

void KeypadShieldClass::processData()
{
  byte function_Number=OneSheeld.getFunctionId();
  //Serial.write(function_Number);
  if (function_Number==DATA_IN)
   { 
     row=OneSheeld.getArgumentData(0)[0];
     col=OneSheeld.getArgumentData(1)[0];
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


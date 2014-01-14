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

void KeypadShieldClass::processData( char * readPacket)
{
  if (readPacket[2]==DATA_IN)
   { 
     row=(int)readPacket[3];
     col=(int)readPacket[4];
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


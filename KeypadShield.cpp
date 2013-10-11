#include "OneSheeld.h"
#include "KeypadShield.h"
#include "HardwareSerial.h"




KeypadShieldClass::KeypadShieldClass()
{
  frameStart=0;
  row=0xf0;
  col=0xf0;
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
  if (readPacket[2]==0x01)
   { 
     row=(int)readPacket[3];
     col=(int)readPacket[4];
   }
   if (isCallbackAssigned)
   (*buttonChangeCallback)(row,col);
}

void KeypadShieldClass::onSerialEvent(char dataByte)
{
 if (!frameStart&&dataByte==STX)
 {
   count=0;
   readPacket[count]=dataByte;
   frameStart=1;
   count++;
 }
 else if (frameStart && (dataByte!=ETX))
 {
  readPacket[count]=dataByte;
  count++;
 }
 else if (frameStart && (dataByte==ETX))
 {
  readPacket[count]=dataByte;
  count=0;
  frameStart=0;
  processData();

 }
 
} 
void KeypadShieldClass::setOnButtonChange(void (*userFunction)(int,int))
{
  buttonChangeCallback=userFunction;
  isCallbackAssigned=true;
}


KeypadShieldClass Keypad;

void serialEvent()
{
char value=Serial.read();
Keypad.onSerialEvent(value);
}
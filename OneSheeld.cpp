/*
  OneSheeld.h - OneSheeld library
  Copyright (C) 2013 Integreight Inc  All rights reserved.
*/

#include "Arduino.h"
#include "HardwareSerial.h"
#include "OneSheeld.h"




// public functions
OneSheeldClass::OneSheeldClass() 
{
  frameStart=0;
}
void OneSheeldClass::begin(long baudRate)
{
  Serial.begin(baudRate);
}
/*
void OneSheeldClass::write(char* data)
{
  write(GENERAL_DATA,NOT_FUNCTION,data);
  delay(1);
}*/

void OneSheeldClass::sendPacket(byte shieldID, byte instanceID, byte functionID, byte argNo, ...)
{
  va_list arguments ;
  va_start (arguments,argNo);

  Serial.write(START_OF_FRAME);
  Serial.write(shieldID);
  Serial.write(instanceID);
  Serial.write(functionID);
  Serial.write(argNo);


  for (int i=0 ; i<argNo ; i++)
  {
    FunctionArg * temp = va_arg(arguments, FunctionArg *);
    Serial.write(temp->getLength());

      for (int j=0 ; j<temp->getLength() ; j++)
      {
        byte* tempData=temp->getData();
        Serial.write(tempData[j]);
      }

 }
    va_end(arguments);
}
/*
void OneSheeldClass::write(char shieldID,char functionCommand, char* data)
{
  int dataLength;
  Serial.write(STX); // send STX  to start the packet
  Serial.write(shieldID);
  Serial.write(functionCommand);
  if (strlen(data)>140)
  dataLength=140;
  else   
  dataLength=strlen(data);
  for(int i=0; i<dataLength; i++) {
    Serial.write(data[i]);        
  }
  
  Serial.write(ETX); // send ETX  to End the packet
  delay(1);
}
void OneSheeldClass::write(char shieldID,char functionCommand, char* data, int length)
{
  int dataLength;
  Serial.write(STX); // send STX  to start the packet
  Serial.write(shieldID);
  Serial.write(functionCommand);
  if (length>140)
  dataLength=140;
  else 
  dataLength=length;
  for(int i=0; i<dataLength; i++) {
    Serial.write(data[i]);        
  }
  
  Serial.write(ETX); // send ETX  to End the packet
  delay(1);
}*/
void OneSheeldClass::onSerialEvent(char dataByte)
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
  sendToShields();
 }
 
} 
void OneSheeldClass::sendToShields()
{
  switch (readPacket[1])
  {
    case 0x33 : Keypad.processData(readPacket); break ;
    case 0x39 : GPS.Proc(readPacket); break ;
    //case 0x41 : Slider.processData(readPacket); break;
   
  }
}
// instantiate object for users
OneSheeldClass OneSheeld;

void serialEvent()
{
char value=Serial.read();
OneSheeld.onSerialEvent(value);
}
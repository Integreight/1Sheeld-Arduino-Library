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
      shield=0;
      Start=0;
      instance=0;
      functions=0;
      counter=0;
      argumentcounter=0;
      datalengthcounter=0;
      argumentnumber=0;
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


//Recieving Functions
byte OneSheeldClass::getShieldId()
{
  return shield;
} 

byte OneSheeldClass::getInstanceId()
{
  return instance;
} 

byte OneSheeldClass::getFunctionId()
{
  return functions;
}

byte OneSheeldClass::getArgumentNo()
{
  return argumentnumber;
} 

byte OneSheeldClass::getArgumentLength(byte x)
{
  return argumentL[x];
}

byte * OneSheeldClass::getArgumentData(byte x)
{
  return arguments[x];
} 

void OneSheeldClass::processInput()
{
  int data=Serial.read();
  if(data==-1)return;
   if(!framestart&&data==0xFF)
        {
            counter=0;
            Start=data;
            framestart=1;
            counter++;
        }
        else if(counter==4)                      //data is the no of arguments
        {
            datalengthcounter=0;
            argumentcounter=0;
            argumentnumber=data;
            arguments=(byte**)malloc(sizeof(byte*)*argumentnumber);//new byte*[argumentnumber];          //assigning the first dimension of the pointer (allocating dynamically space for 2d array)
            argumentL=(byte*)malloc(sizeof(byte)*argumentnumber);//new byte [argumentnumber];
            counter++;
        }
        else if (counter==5)                    // data is the first argument length
        {
            argumentL[argumentcounter]=data;
            arguments[argumentcounter]=(byte*)malloc(sizeof(byte)*argumentL[argumentcounter]); // assigning the second dimensional of the pointer
            counter++;
        }
        else if (counter==6)
        {
            arguments[argumentcounter][datalengthcounter++]=data;
            if (datalengthcounter==argumentL[argumentcounter])
            {
                datalengthcounter=0;
                argumentcounter++;
                counter=5;

                if(argumentcounter==argumentnumber)
                {
                    framestart=0;
                    sendToShields();
                }

            }

        }
        else{
       switch(counter)
       {
                case 1 : shield=data;break;
                case 2 : instance=data;break;
                case 3 : functions=data;break;
                default :               break;
       }
           counter++;
        }

       
    }

void OneSheeldClass::sendToShields()
{
      
  byte number_Of_Shield= OneSheeld.getShieldId();     //getting the shield number using the function we made

  switch (number_Of_Shield)
  {
    case 0x09 : Keypad.processData(); break ;
    case 0x1C : GPS.Proc();break ;
    case 0x01 : Slider.processData(); break;
    case 0x03 : PushButton.processData();break;
    case 0x04 : ToggleButton.processData();break;
    case 0x0C : GamePad.processData();break;
    case 0x13 : Prox.processData();break;
    case 0x18 : Mic.processData();break;
    case 0x12 : Temp.processData();break;
    case 0x10 : Light.processData();break;
    case 0x11 : Pressure.processData();break;
    case 0x14 : Gravity.processData();break;
    case 0x0B : Accelerometer.processData();break;
    case 0x0E : Gyroscope.processData();break;
    case 0x0F : Orientation.processData();break;
    case 0x0A : Magnet.processData();break;
  }
}
// instantiate object for users
OneSheeldClass OneSheeld;

void serialEvent()
{
//byte value=Serial.read();
//OneSheeld.onSerialEvent(value);
OneSheeld.processInput();
}
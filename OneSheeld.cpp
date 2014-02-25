/*
  OneSheeld.h - OneSheeld library
  Copyright (C) 2013 Integreight Inc  All rights reserved.
*/

#include "Arduino.h"
#include "HardwareSerial.h"
#include "OneSheeld.h"




// public functions
OneSheeldClass::OneSheeldClass(Stream &s) :OneSheeldSerial(s)
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
      endFrame!=0;
}

void OneSheeldClass::begin(long baudRate)
{
  #if defined(__AVR_ATmega32U4__)
  Serial1.begin(baudRate);
  #else
  Serial.begin(baudRate);
  #endif
}

void OneSheeldClass::begin()
{
  begin(57600);
}

void OneSheeldClass::sendPacket(byte shieldID, byte instanceID, byte functionID, byte argNo, ...)
{
  va_list arguments ;
  va_start (arguments,argNo);

  OneSheeldSerial.write((byte)START_OF_FRAME);
  OneSheeldSerial.write(shieldID);
  OneSheeldSerial.write(instanceID);
  OneSheeldSerial.write(functionID);
  OneSheeldSerial.write(argNo);


  for (int i=0 ; i<argNo ; i++)
  {
    FunctionArg * temp = va_arg(arguments, FunctionArg *);
    OneSheeldSerial.write(temp->getLength());

      for (int j=0 ; j<temp->getLength() ; j++)
      {
        byte* tempData=temp->getData();
        OneSheeldSerial.write(tempData[j]);
      }

 }
    OneSheeldSerial.write((byte)END_OF_FRAME);
    va_end(arguments);
}

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
  int data=OneSheeldSerial.read();
  if(data==-1)return;
   if(!framestart&&data==0xFF)
        {
            counter=0;
            Start=data;
            framestart=1;
            arguments=0;
            argumentL=0;
            counter++;
        }
        else if(counter==4&&framestart)                      //data is the no of arguments
        {
            datalengthcounter=0;
            argumentcounter=0;
            argumentnumber=data;
            arguments=(byte**)malloc(sizeof(byte*)*argumentnumber);//new byte*[argumentnumber];          //assigning the first dimension of the pointer (allocating dynamically space for 2d array)
            argumentL=(byte*)malloc(sizeof(byte)*argumentnumber);//new byte [argumentnumber];
            counter++;
        }
        else if (counter==5&&framestart)                    // data is the first argument length
        {
            argumentL[argumentcounter]=data;
            arguments[argumentcounter]=(byte*)malloc(sizeof(byte)*argumentL[argumentcounter]); // assigning the second dimensional of the pointer
            counter++;
        }
        else if (counter==6&&framestart)
        {
            arguments[argumentcounter][datalengthcounter++]=data;
            if (datalengthcounter==argumentL[argumentcounter])
            {
                datalengthcounter=0;
                argumentcounter++;
                if(argumentcounter==argumentnumber)
                {
                  counter++;                                    //increment the counter to take the last byte which is the end of the frame

                }
                else
                {
                     counter=5;

                }

            }

        }
        else if(counter==7&&framestart)
        {
          endFrame=data;
            if(endFrame==0)                                   //if the endframe is equal to zero send to shields and free memory
            {
                    framestart=0;
                    sendToShields();
                    if(arguments!=0){
                      for(int i=0;i<argumentnumber;i++)
                      {
                        free(arguments[i]);
                      }
                      free(arguments);
                    }
                    if(argumentL!=0)free(argumentL);
                    
            }
            else                                            //if endframe wasn't equal to zero make sure that the memory is free anyway
            {
              framestart=0;
              if(arguments!=0){
                      for(int i=0;i<argumentnumber;i++)
                      {
                        free(arguments[i]);
                      }
                      free(arguments);
                    }
                    if(argumentL!=0)free(argumentL);
            }
        }
        else if(framestart){
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
    case 0x1C : GPS.processData();break ;
    case 0x01 : Slider.processData(); break;
    case 0x03 : PushButton.processData();break;
    case 0x04 : ToggleButton.processData();break;
    case 0x0C : GamePad.processData();break;
    case 0x13 : ProximitySensor.processData();break;
    case 0x18 : Mic.processData();break;
    case 0x12 : TemperatureSensor.processData();break;
    case 0x10 : LightSensor.processData();break;
    case 0x11 : PressureSensor.processData();break;
    case 0x14 : Gravity.processData();break;
    case 0x0B : Accelerometer.processData();break;
    case 0x0E : Gyroscope.processData();break;
    case 0x0F : OrientationSensor.processData();break;
    case 0x0A : Magnetometer.processData();break;
    case 0x20 : Phone.processData();break;
    case 0x0D : SMS.processData();break;
  }
}
// instantiate object for users
#if defined(__AVR_ATmega32U4__)
OneSheeldClass OneSheeld(Serial1);
void serialEvent1()
#else
OneSheeldClass OneSheeld(Serial);
void serialEvent()
#endif
{
  while(OneSheeld.OneSheeldSerial.available())OneSheeld.processInput();      //takes all the bytes and save them in the buffer (buffer size = 64bits)
}
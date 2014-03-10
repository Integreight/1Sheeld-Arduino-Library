/*
  OneSheeld.h - OneSheeld library
  Copyright (C) 2013 Integreight Inc  All rights reserved.
*/
#include "OneSheeld.h"
#include "HardwareSerial.h"
#include "Arduino.h"




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
      lastTimeFrameSent=0;
      isFirstFrame=false;
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
  unsigned long mill=millis()+1;
 if(isFirstFrame&&lastTimeFrameSent&&(mill-lastTimeFrameSent)<TIME_GAP) 
    delay(TIME_GAP-(mill-lastTimeFrameSent));
  isFirstFrame=true;
  va_list arguments ;
  va_start (arguments,argNo);
  OneSheeldSerial.write((byte)START_OF_FRAME);
  OneSheeldSerial.write(LIBRARY_VERSION);
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
    delete(temp);

 }
    OneSheeldSerial.write((byte)END_OF_FRAME);
    va_end(arguments);
    lastTimeFrameSent=millis()+1;
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
  while(OneSheeld.OneSheeldSerial.available()){
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
       
    }
void OneSheeldClass::sendToShields()
{
      
  byte number_Of_Shield= OneSheeld.getShieldId();     //getting the shield number using the function we made

  switch (number_Of_Shield)
  {
    case KEYPAD_SHIELD_ID        : Keypad.processData(); break ;
    case GPS_ID                  : GPS.processData();break ;
    case SLIDER_ID               : Slider.processData(); break;
    case PUSH_BUTTON_ID          : PushButton.processData();break;
    case TOGGLE_BUTTON_ID        : ToggleButton.processData();break;
    case GAMEPAD_ID              : GamePad.processData();break;
    case PROXIMITY_ID            : ProximitySensor.processData();break;
    case MIC_ID                  : Mic.processData();break;
    case TEMPERATURE_ID          : TemperatureSensor.processData();break;
    case LIGHT_ID                : LightSensor.processData();break;
    case PRESSURE_ID             : PressureSensor.processData();break;
    case GRAVITY_ID              : Gravity.processData();break;
    case ACCELEROMETER_ID        : Accelerometer.processData();break;
    case GYROSCOPE_ID            : Gyroscope.processData();break;
    case ORIENTATION_ID          : OrientationSensor.processData();break;
    case MAGNETOMETER_ID         : Magnetometer.processData();break;
    case PHONE_ID                : Phone.processData();break;
    case SMS_ID                  : SMS.processData();break;
    case CLOCK_ID                : Clock.processData();break;
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
  OneSheeld.processInput();      //takes all the bytes and save them in the buffer (buffer size = 64bits)
}
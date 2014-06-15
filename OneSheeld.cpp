/*

  Project:       1Sheeld Library 
  File:          OneSheeld.cpp
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/
  
#include "OneSheeld.h"
#include "HardwareSerial.h"
#include "Arduino.h"
#include "stdarg.h"

//Shields ID's
byte inputShieldsList[]={KEYPAD_SHIELD_ID
,GPS_ID
,SLIDER_ID
,PUSH_BUTTON_ID
,TOGGLE_BUTTON_ID
,GAMEPAD_ID
,PROXIMITY_ID
,MIC_ID
,TEMPERATURE_ID
,LIGHT_ID
,PRESSURE_ID
,GRAVITY_ID
,ACCELEROMETER_ID
,GYROSCOPE_ID
,ORIENTATION_ID
,MAGNETOMETER_ID
,PHONE_ID
,SMS_ID
,CLOCK_ID
,KEYBOARD_ID
,TWITTER_ID};


//Class Constructor
OneSheeldClass::OneSheeldClass(Stream &s) :OneSheeldSerial(s)
{
      shield=0;
      instance=0;
      functions=0;
      counter=0;
      argumentcounter=0;
      datalengthcounter=0;
      argumentnumber=0;
      endFrame=0;
      lastTimeFrameSent=0;
      isFirstFrame=false;
}

//Library Starter
void OneSheeldClass::begin(long baudRate)
{
  #if defined(__AVR_ATmega32U4__)
  Serial1.begin(baudRate);
  #else
  Serial.begin(baudRate);
  #endif
}
//Library Starter
void OneSheeldClass::begin()
{
  begin(115200);
}

//Frame Sender for Output Shields
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
  OneSheeldSerial.write(255-argNo);


  for (int i=0 ; i<argNo ; i++)
  {
    FunctionArg * temp = va_arg(arguments, FunctionArg *);
    OneSheeldSerial.write(temp->getLength());
    OneSheeldSerial.write(255-(temp->getLength()));

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

//Shield_ID Getter
byte OneSheeldClass::getShieldId()
{
  return shield;
} 
//Instance_ID Getter
byte OneSheeldClass::getInstanceId()
{
  return instance;
} 
//Funtcion_ID Getter
byte OneSheeldClass::getFunctionId()
{
  return functions;
}
//ArgumentsNumber Getter
byte OneSheeldClass::getArgumentNo()
{
  return argumentnumber;
} 
//ArgumentLength Getter
byte OneSheeldClass::getArgumentLength(byte x)
{
  return argumentL[x];
}
//Data Getter
byte * OneSheeldClass::getArgumentData(byte x)
{
  return arguments[x];
} 

//Incomming Frames processing 
void OneSheeldClass::processInput()
{
  while(OneSheeld.OneSheeldSerial.available()){
    int data=OneSheeldSerial.read();
    if(data==-1)return;
     if(!framestart&&data==0xFF)
          {
              counter=0;
              framestart=true;
              arguments=0;
              argumentL=0;
              counter++;
          }
          else if(counter==4&&framestart)                      //data is the no of arguments
          {
              datalengthcounter=0;
              argumentcounter=0;
              argumentnumber=data;
              counter++;
          }
          else if(counter==5&&framestart)                      //data is the no of arguments
          {
              if((255-argumentnumber)==data){
              arguments=(byte**)malloc(sizeof(byte*)*argumentnumber);//new byte*[argumentnumber];          //assigning the first dimension of the pointer (allocating dynamically space for 2d array)
              argumentL=(byte*)malloc(sizeof(byte)*argumentnumber);//new byte [argumentnumber];
              counter++;
              }
              else{
                framestart=false;
                continue;
              }


          }
          else if (counter==6&&framestart)                    // data is the first argument length
          {
              argumentL[argumentcounter]=data;
              counter++;
          }
          else if (counter==7&&framestart)                    // data is the first argument Data information
          {
            if((255-argumentL[argumentcounter])==data){
              arguments[argumentcounter]=(byte*)malloc(sizeof(byte)*argumentL[argumentcounter]); // assigning the second dimensional of the pointer
              counter++;
            }
            else{
                framestart=false;
                continue;
              }
          }
          else if (counter==8&&framestart)
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
                       counter=6;

                  }

              }

          }
          else if(counter==9&&framestart)
          {
            endFrame=data;
              if(endFrame==0)                                   //if the endframe is equal to zero send to shields and free memory
              {
                      framestart=false;
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
                framestart=false;
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
                if(counter==1){
                  shield=data;
                  bool found = false;
                  for (int i=0;i<21;i++) {
                    if (shield == inputShieldsList[i]){
                      found = true;
                      
                    }
                  }
                  if (!found) {
                    framestart=false;
                    continue;
                  }
                }
                else if(counter==2)instance=data;
                else if(counter==3)functions=data;
            counter++;
          }
      }
       
    }
//Data Sender to Input Shields
void OneSheeldClass::sendToShields()
{
  //Checking the Shield-ID    
  byte number_Of_Shield= OneSheeld.getShieldId();     
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
    case GRAVITY_ID              : GravitySensor.processData();break;
    case ACCELEROMETER_ID        : AccelerometerSensor.processData();break;
    case GYROSCOPE_ID            : GyroscopeSensor.processData();break;
    case ORIENTATION_ID          : OrientationSensor.processData();break;
    case MAGNETOMETER_ID         : MagnetometerSensor.processData();break;
    case PHONE_ID                : Phone.processData();break;
    case SMS_ID                  : SMS.processData();break;
    case CLOCK_ID                : Clock.processData();break;
    case KEYBOARD_ID             : AsciiKeyboard.processData();break;
    case TWITTER_ID              : Twitter.processData();break;
  }
}
/*
//PulseWidthModulation Getter 
unsigned char OneSheeldClass::analogRead(int pin)
{
    double period=(double)pulseIn(pin,HIGH)+(double)pulseIn(pin,LOW);;
    double duty=(double)pulseIn(pin,HIGH);
    double fraction=duty/period;
    unsigned char pwm_out=(unsigned char)(ceil)(fraction*255);
    return pwm_out;
}*/
    
//Instantiating Object
#if defined(__AVR_ATmega32U4__)
OneSheeldClass OneSheeld(Serial1);
void serialEvent1()
#else
OneSheeldClass OneSheeld(Serial);
void serialEvent()
#endif
{
  OneSheeld.processInput();      
}
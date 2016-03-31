/*

  Project:       1Sheeld Library 
  File:          OneSheeld.cpp
                 
  Version:       1.2

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/
#define FROM_ONESHEELD_LIBRARY
#include "OneSheeld.h"
#include "HardwareSerial.h"
#include "stdarg.h"

bool OneSheeldClass::isInit=false;
bool OneSheeldClass::isSws=false;
byte OneSheeldClass::shieldsCounter=0;
unsigned long OneSheeldClass::lastTimeFrameSent=0;
bool OneSheeldClass::inACallback=false;
bool OneSheeldClass::callbacksInterrupts=false;
bool OneSheeldClass::isFirstFrame=false;
ShieldParent * OneSheeldClass::shieldsArray[]={0};
// #ifdef INTERNET_SHIELD
byte OneSheeldClass::requestsCounter=0;
HttpRequest ** OneSheeldClass::requestsArray=(HttpRequest**)malloc(sizeof(HttpRequest*)*MAX_NO_OF_REQUESTS);
// #endif
//Class Constructor
OneSheeldClass::OneSheeldClass()
{
      shield=0;
      verificationByte=0;
      functions=0;
      counter=0;
      argumentcounter=0;
      datalengthcounter=0;
      argumentnumber=0;
      endFrame=0;
      numberOfDataMalloced=0;
      isArgumentsNumberMalloced=false;
      isArgumentLengthMalloced=false;
      callbacksInterrupts=false;
      framestart =false;
      isOneSheeldConnected =false;
      isAppConnectionCallBack = false;
      isShieldFrameCallback = false;
      isSerialDataCallback = false;
      OneSheeldSerial=0;
}

//Library Starter
void OneSheeldClass::begin(long baudRate)
{
  #if defined(__AVR_ATmega32U4__) || defined(ARDUINO_LINUX)
  OneSheeldSerial=&Serial1;
  Serial1.begin(baudRate);
  #else
  OneSheeldSerial=&Serial;
  Serial.begin(baudRate);
  #endif
}
//Blocking function 
void OneSheeldClass::waitForAppConnection()
{
  isOneSheeldConnected = false;

  while(!isOneSheeldConnected)
  {
    OneSheeld.processInput();
  }

}
//Library Starter
void OneSheeldClass::begin()
{
  begin(115200);
  isSws=false;
  sendShieldFrame(ONESHEELD_ID,0,CHECK_APP_CONNECTION,0);
  isInit=true;
  // #ifdef INTERNET_SHIELD
  for(int i=0;i<requestsCounter;i++)
    requestsArray[i]->sendInitFrame();
  free(requestsArray);
  // #endif
}

//Library Starter
void OneSheeldClass::begin(Stream &s)
{
  OneSheeldSerial=&s;
  isSws=true;
  sendShieldFrame(ONESHEELD_ID,0,CHECK_APP_CONNECTION,0);
  isInit=true;
  // #ifdef INTERNET_SHIELD
  for(int i=0;i<requestsCounter;i++)
    requestsArray[i]->sendInitFrame();
  free(requestsArray);
  // #endif
}

void OneSheeldClass::addToShieldsArray(ShieldParent * shield)
{
  if(shieldsCounter==SHIELDS_NO) return;
  shieldsArray[shieldsCounter++] = shield;  
}
// #ifdef INTERNET_SHIELD
void OneSheeldClass::addToUnSentRequestsArray(HttpRequest * request)
{
  if(requestsCounter==MAX_NO_OF_REQUESTS) return;
  requestsArray[requestsCounter++] = request;  
}
// #endif
bool OneSheeldClass::isInitialized()
{
  return isInit;
}

bool OneSheeldClass::isSoftwareSerial()
{
  return isSws;
}

void OneSheeldClass::setOnNewShieldFrame(void (*userFunction)(byte shieldID, byte functionID, byte argNo,byte *argumentL,byte **arguments))
{
  isShieldFrameCallback=true;
  shieldFrameCallback=userFunction;
}

void OneSheeldClass::setOnNewSerialData(void (*userFunction)(byte))
{
  isSerialDataCallback=true;
  serialDataCallback=userFunction;
}

//Frame Sender for Output Shields
void OneSheeldClass::sendShieldFrame(byte shieldID, byte instanceID, byte functionID, byte argNo, ...)
{
  unsigned long mill=millis()+1;
  unsigned long localLastTimeFrameSent=lastTimeFrameSent;
  if(shieldID!=ONESHEELD_ID&&isFirstFrame&&localLastTimeFrameSent&&(mill-localLastTimeFrameSent)<TIME_GAP){
  if(inACallback){
     OneSheeldClass TempOneSheeld;
     ShieldParent::setOneSheeldInstance(TempOneSheeld);
     while((millis()<(TIME_GAP+localLastTimeFrameSent))||TempOneSheeld.framestart)
     {
        if(TempOneSheeld.OneSheeldSerial->available())
          TempOneSheeld.processInput(TempOneSheeld.OneSheeldSerial->read());
     }
      ShieldParent::unSetOneSheeldInstance();
   }else
      while((millis()<(TIME_GAP+localLastTimeFrameSent))||framestart)
      {
        if(OneSheeldSerial->available())
          OneSheeld.processInput(OneSheeldSerial->read());
      }
  }

  isFirstFrame=true;
  va_list arguments ;
  va_start (arguments,argNo);
  OneSheeldSerial->write((byte)START_OF_FRAME);
  OneSheeldSerial->write(LIBRARY_VERSION);
  OneSheeldSerial->write(shieldID);
  OneSheeldSerial->write(getVerificationByte());
  OneSheeldSerial->write(functionID);
  OneSheeldSerial->write(argNo);
  OneSheeldSerial->write(255-argNo);


  for (int i=0 ; i<argNo ; i++)
  {
    FunctionArg * temp = va_arg(arguments, FunctionArg *);
    OneSheeldSerial->write(temp->getLength());
    OneSheeldSerial->write(255-(temp->getLength()));

      for (int j=0 ; j<temp->getLength() ; j++)
      {
        byte* tempData=temp->getData();
        OneSheeldSerial->write(tempData[j]);
      }
    delete(temp);

 }
    OneSheeldSerial->write((byte)END_OF_FRAME);
    va_end(arguments);
    if(shieldID!=ONESHEELD_ID)lastTimeFrameSent=millis()+1;
}

void OneSheeldClass::sendShieldFrame(byte shieldID, byte instanceID, byte functionID, byte argNo, FunctionArg ** arguments)
{
  unsigned long mill=millis()+1;
  unsigned long localLastTimeFrameSent=lastTimeFrameSent;
  if(shieldID!=ONESHEELD_ID&&isFirstFrame&&localLastTimeFrameSent&&(mill-localLastTimeFrameSent)<TIME_GAP){
  if(inACallback){
     OneSheeldClass TempOneSheeld;
     ShieldParent::setOneSheeldInstance(TempOneSheeld);
     while((millis()<(TIME_GAP+localLastTimeFrameSent))||TempOneSheeld.framestart)
     {
        if(TempOneSheeld.OneSheeldSerial->available())
          TempOneSheeld.processInput(TempOneSheeld.OneSheeldSerial->read());
     }
      ShieldParent::unSetOneSheeldInstance();
   }else
      while((millis()<(TIME_GAP+localLastTimeFrameSent))||framestart)
      {
        if(OneSheeldSerial->available())
          OneSheeld.processInput(OneSheeldSerial->read());
      }
  }

  isFirstFrame=true;
  OneSheeldSerial->write((byte)START_OF_FRAME);
  OneSheeldSerial->write(LIBRARY_VERSION);
  OneSheeldSerial->write(shieldID);
  OneSheeldSerial->write(getVerificationByte());
  OneSheeldSerial->write(functionID);
  OneSheeldSerial->write(argNo);
  OneSheeldSerial->write(255-argNo);
  
  for (int i=0 ; i<argNo ; i++)
  {
    OneSheeldSerial->write(arguments[i]->getLength());
    OneSheeldSerial->write(255-(arguments[i]->getLength()));
      for (int j=0 ; j<arguments[i]->getLength() ; j++)
      {
        byte* tempData=arguments[i]->getData();
        OneSheeldSerial->write(tempData[j]);
      }
 }
    OneSheeldSerial->write((byte)END_OF_FRAME);
    if(shieldID!=ONESHEELD_ID)lastTimeFrameSent=millis()+1;
}
bool OneSheeldClass::isAppConnected()
{
  return isOneSheeldConnected;
}
void OneSheeldClass::setOnAppConnected(void (*userFunction)(bool isAppConnected))
{
  isAppConnectedCallBack = userFunction;
  isAppConnectionCallBack = true;
}
//Shield_ID Getter
byte OneSheeldClass::getShieldId()
{
  return shield;
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
  if(argumentL[x]!=0)
    return arguments[x];
  else return NULL;
}

//Convert float to array of bytes
byte * OneSheeldClass::convertFloatToBytes(float data)
{
  convertFloatUnion.number = data;
  return convertFloatUnion.floatBytes;
} 

//Convert array of bytes to float
float OneSheeldClass::convertBytesToFloat(byte * data)
{
  convertFloatUnion.floatBytes[0] = data[0];
  convertFloatUnion.floatBytes[1] = data[1];
  convertFloatUnion.floatBytes[2] = data[2];
  convertFloatUnion.floatBytes[3] = data[3];
  return convertFloatUnion.number;
} 

//Incomming Frames processing 
void OneSheeldClass::processInput(int data) 
{
    if(data==-1)return;
     if(!framestart&&data==START_OF_FRAME)
          {
              freeMemoryAllocated();
              counter=0;
              framestart=true;
              arguments=0;
              argumentL=0;
              counter++;
              #ifdef DEBUG
              Serial.print("C1 ");
              #endif
          }
          else if(counter==4&&framestart)                      //data is the no of arguments
          {
              #ifdef DEBUG
              Serial.print("C4 ");
              #endif
              datalengthcounter=0;
              argumentcounter=0;
              argumentnumber=data;
              counter++;
          }
          else if(counter==5&&framestart)                      //data is the no of arguments
          {
              #ifdef DEBUG
              Serial.print("C5 ");
              #endif
              if((255-argumentnumber)==data&&argumentnumber==0){
                counter=9;
                return;
              }
              else if((255-argumentnumber)==data){
              arguments=(byte**)malloc(sizeof(byte*)*argumentnumber);//new byte*[argumentnumber];          //assigning the first dimension of the pointer (allocating dynamically space for 2d array)
              #ifdef DEBUG
              Serial.print("M1 ");
              #endif
              isArgumentsNumberMalloced=true;
              argumentL=(byte*)malloc(sizeof(byte)*argumentnumber);//new byte [argumentnumber];
              #ifdef DEBUG
              Serial.print("M2 ");
              #endif
              isArgumentLengthMalloced=true;
              counter++;
              }
              else{
                framestart=false;
                freeMemoryAllocated();
                return;
              }


          }
          else if (counter==6&&framestart)                    // data is the first argument length
          {
              #ifdef DEBUG
              Serial.print("C6 ");
              #endif
              argumentL[argumentcounter]=data;
              counter++;
          }
          else if (counter==7&&framestart)                    // data is the first argument Data information
          {
            #ifdef DEBUG
            Serial.print("C7 ");
            #endif
            if((255-argumentL[argumentcounter])==data){
              if(argumentL[argumentcounter]!=0)
              {
                arguments[argumentcounter]=(byte*)malloc(sizeof(byte)*argumentL[argumentcounter]); // assigning the second dimensional of the pointer
                #ifdef DEBUG
                Serial.print("M3 ");
                #endif
                counter++;
              }
              else
              {
                arguments[argumentcounter]=NULL;
                datalengthcounter=0;
                argumentcounter++;
                if(argumentcounter==argumentnumber)
                  counter=9;
                else
                  counter=6;
              }
              numberOfDataMalloced++;
            }
            else{
                framestart=false;
                freeMemoryAllocated();
                return;
              }
          }
          else if (counter==8&&framestart)
          {
              #ifdef DEBUG
              Serial.print("C8 ");
              #endif
              if(arguments[argumentcounter]!=NULL)arguments[argumentcounter][datalengthcounter++]=data;
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
              #ifdef DEBUG
              Serial.print("C9 ");
              #endif
            endFrame=data;
              if(endFrame==END_OF_FRAME)                                   //if the endframe is equal to zero send to shields and free memory
              {
                      sendToShields();
                      if(isShieldFrameCallback)
                      {
                        enteringACallback();
                        shieldFrameCallback(shield,functions,argumentnumber,argumentL,arguments);
                        exitingACallback();
                      }
                      freeMemoryAllocated();
                      
              }
              else                                            //if endframe wasn't equal to zero make sure that the memory is free anyway
              {
                freeMemoryAllocated();
              }
          }
          else if(framestart){
                if(counter==1){
                  shield=data;
                  bool found = false;
                  if(shield == ONESHEELD_ID || isShieldFrameCallback) found = true;
                  else 
                  for (int i=0;i<shieldsCounter;i++) {
                    if (shield == shieldsArray[i]->getShieldId()){
                      found = true;
                      
                    }
                  }
                  if (!found) {
                    framestart=false;
                    freeMemoryAllocated();
                    return;
                  }
                }
                else if(counter==2){
                  verificationByte=data;
                  byte leastBits = verificationByte & 0x0F;
                  if((255-verificationByte>>4) != leastBits) framestart =false;
                  #ifdef DEBUG
                  Serial.print("C2 ");
                  #endif
                }
                else if(counter==3){
                  functions=data;
                  #ifdef DEBUG
                  Serial.print("C3 ");
                  #endif
                }
            counter++;
          }

}

void OneSheeldClass::processInput()
{
  while(OneSheeldSerial->available())
  {
    byte data=OneSheeldSerial->read();
    processInput(data);
    if(isSerialDataCallback)
    {
      enteringACallback();
      serialDataCallback(data);
      exitingACallback();
    }
      
  }
}

void OneSheeldClass::freeMemoryAllocated(){
  framestart=false;
  if(isArgumentsNumberMalloced){
          for(int i=0;i<numberOfDataMalloced;i++)
          {
            if(arguments[i]!=NULL)free(arguments[i]);
            #ifdef DEBUG
            Serial.print("F3 ");
            #endif
          }
          numberOfDataMalloced=0;
          free(arguments);
          #ifdef DEBUG
          Serial.print("F1 ");
          #endif
          isArgumentsNumberMalloced=false;
        }
        if(isArgumentLengthMalloced){
          free(argumentL);
          #ifdef DEBUG
          Serial.println("F2 ");
          #endif
          isArgumentLengthMalloced=false;
        }
}

//Data Sender to Input Shields
void OneSheeldClass::sendToShields()
{
  //Checking the Shield-ID    
  byte number_Of_Shield= OneSheeld.getShieldId();     
  switch (number_Of_Shield)
  {
    case ONESHEELD_ID            :processFrame();break;
    default:
    for(int i=0 ;i<shieldsCounter;i++)
    {
      shieldsArray[i]->processFrame();
    }
  }
}

void OneSheeldClass::processFrame(){
  byte functionId = getFunctionId();
  //Check  the function ID 
  if(functionId == DISCONNECTION_CHECK_FUNCTION)
  {
      isOneSheeldConnected=false;
      if(isAppConnectionCallBack)(*isAppConnectedCallBack)(isOneSheeldConnected);
  }
  else if(functionId == CONNECTION_CHECK_FUNCTION)
  {
      isOneSheeldConnected=true;
      if(isAppConnectionCallBack)(*isAppConnectedCallBack)(isOneSheeldConnected);
  }
  else if(functionId == LIBRARY_VERSION_REQUEST)
  {
    sendShieldFrame(ONESHEELD_ID,0,SEND_LIBRARY_VERSION,0);
  }
  else if(functionId == LIBRARY_TESTING_REQUEST)
  {
    if(!memcmp("Are you ok?",getArgumentData(0),11))
    {
      const char * responseString = "Yup, I'm feeling great!";
      byte testAnswer = 0;
      int sumOfData = 0;
      for(int i = 0 ; i < getArgumentLength(1) ; i++)
      {
        sumOfData+= getArgumentData(1)[i];
      }
      testAnswer = sumOfData%256;
      sendShieldFrame(ONESHEELD_ID,0x00,LIBRARY_TESTING_RESPONSE,2,new FunctionArg(23,(byte *)responseString),new FunctionArg(1,&testAnswer));
    }
  }
}

//PulseWidthModulation Getter 
unsigned char OneSheeldClass::analogRead(int pin)
{
    double period=(double)pulseIn(pin,HIGH)+(double)pulseIn(pin,LOW);;
    double duty=(double)pulseIn(pin,HIGH);
    double fraction=duty/period;
    unsigned char pwm_out=(unsigned char)(ceil)(fraction*255);
    return pwm_out;
}

void OneSheeldClass::enteringACallback()
{
  if(!isInACallback())
  {
    inACallback=true;
    sendShieldFrame(ONESHEELD_ID,0,CALLBACK_ENTERED,0);
  }
}

void OneSheeldClass::exitingACallback()
{
  if(isInACallback())
  {
    inACallback=false;
    sendShieldFrame(ONESHEELD_ID,0,CALLBACK_EXITED,0);
  }
}

bool OneSheeldClass::isInACallback()
{
  return inACallback && !callbacksInterrupts;
}

bool OneSheeldClass::isCallbacksInterruptsSet()
{
  return callbacksInterrupts;
}

void OneSheeldClass::disableCallbacksInterrupts()
{
   callbacksInterrupts=false;
}

void OneSheeldClass::enableCallbacksInterrupts()
{
   callbacksInterrupts=true;
}

void OneSheeldClass::delay(unsigned long time)
{
  unsigned long now=millis();
    if(inACallback)
    {
     OneSheeldClass TempOneSheeld;
     ShieldParent::setOneSheeldInstance(TempOneSheeld);
     while((millis()<(now+time))||TempOneSheeld.framestart)
     {
        if(TempOneSheeld.OneSheeldSerial->available())
          TempOneSheeld.processInput(TempOneSheeld.OneSheeldSerial->read());
      }
      ShieldParent::unSetOneSheeldInstance();
   }else
      while((millis()<(now+time))||framestart)
      {
        if(OneSheeldSerial->available())
          OneSheeld.processInput(OneSheeldSerial->read());
      }
}
OneSheeldClass OneSheeld;
//Instantiating Object
#if defined(__AVR_ATmega32U4__) || defined(ARDUINO_LINUX)
void serialEvent1()
#else
void serialEvent()
#endif
{
  if(!OneSheeld.isSoftwareSerial())OneSheeld.processInput();      
}

byte OneSheeldClass::getVerificationByte()
{
  byte randomValue = (byte)random(0,16);
  byte randomValueComplement = ~(randomValue);
  randomValue&=0x0F;
  randomValue = randomValue|(randomValueComplement<<4);
  return randomValue;
}
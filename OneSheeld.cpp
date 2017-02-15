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
unsigned long OneSheeldClass::argumentDataBytesTimeReceived=0;
bool OneSheeldClass::inACallback=false;
bool OneSheeldClass::callbacksInterrupts=false;
bool OneSheeldClass::isFirstFrame=false;
ShieldParent * OneSheeldClass::shieldsArray[]={0};
Stream * OneSheeldClass::OneSheeldSerial = 0;
// #ifdef INTERNET_SHIELD
byte OneSheeldClass::requestsCounter=0;
HttpRequest ** OneSheeldClass::requestsArray=0;
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
      dontDelay = false;
}

//Library Starter
void OneSheeldClass::begin(long baudRate)
{
  #if(defined(__AVR_ATmega32U4__) || \
     defined(ARDUINO_LINUX) || \
     defined(__MK20DX128__) || \
     defined(__MK20DX256__) || \
     defined(__MKL26Z64__) || \
     defined(_VARIANT_ARDUINO_101_X_) || \
     defined(_VARIANT_ARDUINO_ZERO_))
  
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

void OneSheeldClass::init()
{
  isInit=true;
  sendShieldFrame(ONESHEELD_ID,0,CHECK_APP_CONNECTION,0);
  if(requestsArray!=0){
    for(int i=0;i<requestsCounter;i++)
      requestsArray[i]->sendInitFrame();
    free(requestsArray);
    requestsCounter=0;
  }
}

//Library Starter
void OneSheeldClass::begin()
{
  if(!isInit){
    begin(115200);
    isSws=false;
    init();
  }
}

//Library Starter
void OneSheeldClass::begin(Stream &s)
{
  if(!isInit){
    OneSheeldSerial=&s;
    isSws=true;
    init();
  }
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
  if(requestsCounter<=0)
    requestsArray=(HttpRequest**)malloc(sizeof(HttpRequest*)*MAX_NO_OF_REQUESTS);
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
void OneSheeldClass::oneSheeldWrite(byte data)
{
  if(isInit)OneSheeldSerial->write(data);
  if(!dontDelay)
  {
    ::delay(2);
  }
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
  oneSheeldWrite((byte)START_OF_FRAME);
  oneSheeldWrite(LIBRARY_VERSION);
  oneSheeldWrite(shieldID);
  oneSheeldWrite(getVerificationByte());
  oneSheeldWrite(functionID);
  oneSheeldWrite(argNo);
  oneSheeldWrite(255-argNo);


  for (int i=0 ; i<argNo ; i++)
  {
    FunctionArg * temp = va_arg(arguments, FunctionArg *);
    oneSheeldWrite(temp->getLength());
    oneSheeldWrite(255-(temp->getLength()));

      for (int j=0 ; j<temp->getLength() ; j++)
      {
        byte* tempData=temp->getData();
        oneSheeldWrite(tempData[j]);
      }
    delete(temp);

 }
    oneSheeldWrite((byte)END_OF_FRAME);
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
  oneSheeldWrite((byte)START_OF_FRAME);
  oneSheeldWrite(LIBRARY_VERSION);
  oneSheeldWrite(shieldID);
  oneSheeldWrite(getVerificationByte());
  oneSheeldWrite(functionID);
  oneSheeldWrite(argNo);
  oneSheeldWrite(255-argNo);
  
  for (int i=0 ; i<argNo ; i++)
  {
    oneSheeldWrite(arguments[i]->getLength());
    oneSheeldWrite(255-(arguments[i]->getLength()));
      for (int j=0 ; j<arguments[i]->getLength() ; j++)
      {
        byte* tempData=arguments[i]->getData();
        oneSheeldWrite(tempData[j]);
      }
 }
    oneSheeldWrite((byte)END_OF_FRAME);
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
void OneSheeldClass::convertFloatToBytes(float data, byte * out)
{
  FloatUnion f2bUnion;
  f2bUnion.number = data;
  out[0]=f2bUnion.floatBytes[0];
  out[1]=f2bUnion.floatBytes[1];
  out[2]=f2bUnion.floatBytes[2];
  out[3]=f2bUnion.floatBytes[3];
} 

//Convert array of bytes to float
float OneSheeldClass::convertBytesToFloat(byte * data)
{
  FloatUnion b2fUnion;
  b2fUnion.floatBytes[0] = data[0];
  b2fUnion.floatBytes[1] = data[1];
  b2fUnion.floatBytes[2] = data[2];
  b2fUnion.floatBytes[3] = data[3];
  return b2fUnion.number;
} 

//Incomming Frames processing 
void OneSheeldClass::processInput(int data) 
{
    if(data==-1)return;
    if((millis() - argumentDataBytesTimeReceived) > 2000 && argumentDataBytesTimeReceived !=0 && framestart) 
      {
        freeMemoryAllocated();
      }
      argumentDataBytesTimeReceived = millis();
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
                      framestart=false;
                      sendToShields();
                      if(isShieldFrameCallback && shield!=0)
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
                  if(((255-verificationByte)>>4) != leastBits) framestart =false;
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
    dontDelay = true;
    sendShieldFrame(ONESHEELD_ID,0,CALLBACK_ENTERED,0);
    dontDelay = false;
  }
}

void OneSheeldClass::exitingACallback()
{
  if(isInACallback())
  {
    inACallback=false;
    dontDelay = true;
    sendShieldFrame(ONESHEELD_ID,0,CALLBACK_EXITED,0);
    dontDelay = false;
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
#if(defined(__AVR_ATmega32U4__) || \
     defined(ARDUINO_LINUX) || \
     defined(__MK20DX128__) || \
     defined(__MK20DX256__) || \
     defined(__MKL26Z64__) || \
     defined(_VARIANT_ARDUINO_101_X_) || \
     defined(_VARIANT_ARDUINO_ZERO_))
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
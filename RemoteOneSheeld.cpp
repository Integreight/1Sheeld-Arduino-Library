/*

  Project:       1Sheeld Library 
  File:          RemoteOneSheeld.cpp
                 
  Version:       1.3

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.12

*/

#include "OneSheeld.h"
#include "RemoteOneSheeld.h"





//Constructor
RemoteOneSheeld::RemoteOneSheeld(const char * address):remoteOneSheeldAddress(address)
{
	isFloatMessageAssigned=false;
	isStringMessageAssigned=false;
	isSubscribeAssigned=false;
	usedSetOnFloatWithString=false;
	usedSetOnStringWithString=false;
	incommingFloatValue = 0;
}
//Setting Pins mode
void RemoteOneSheeld::pinMode(byte pinNumber, byte pinDirection)
{
	pinNumber =checkAnalogPinNumbers(pinNumber);
	
	if((pinNumber>= 0||pinNumber <= 19) && (pinDirection == 0 || pinDirection == 1))
	{
		OneSheeld.sendPacket(REMOTE_SHEELD_ID,0,REMOTEONESHEELD_PIN_MODE,3,
						new FunctionArg(strlen(remoteOneSheeldAddress),(byte*)remoteOneSheeldAddress),
						new FunctionArg(1,&pinNumber),
						new FunctionArg(1,&pinDirection));
	}
	
}
//Setting digital pin state
void RemoteOneSheeld::digitalWrite(byte pinNumber,byte pinValue)
{
	pinNumber =checkAnalogPinNumbers(pinNumber);

	if((pinNumber>= 0 && pinNumber <= 19) && (pinValue == 0 || pinValue == 1))
	{
		OneSheeld.sendPacket(REMOTE_SHEELD_ID,0,REMOTEONESHEELD_WRITE,3,
						new FunctionArg(strlen(remoteOneSheeldAddress),(byte*)remoteOneSheeldAddress),
						new FunctionArg(1,&pinNumber),
						new FunctionArg(1,&pinValue));
	}

}
//Setting analog pin status
void RemoteOneSheeld::analogWrite(byte pinNumber,int pinValue)
{
	byte tempValue ;
	pinNumber =checkAnalogPinNumbers(pinNumber);

	if(pinValue<0) pinValue=0;
	if(pinValue>255) pinValue=255;

	tempValue = (byte)pinValue;

	if((pinNumber==5||pinNumber==6||pinNumber==9||pinNumber==10||pinNumber==11)||(pinNumber>=14 && pinNumber<=19))
	{
		OneSheeld.sendPacket(REMOTE_SHEELD_ID,0,REMOTEONESHEELD_ANALOG_WRITE,3,
						new FunctionArg(strlen(remoteOneSheeldAddress),(byte*)remoteOneSheeldAddress),
						new FunctionArg(1,&pinNumber),
						new FunctionArg(1,&tempValue));
	}
}
//Getting digital/analog pin status 
void RemoteOneSheeld::digitalRead(byte pinNumber)
{
	OneSheeld.sendPacket(REMOTE_SHEELD_ID,0,REMOTEONESHEELD_READ,2,
						new FunctionArg(strlen(remoteOneSheeldAddress),(byte*)remoteOneSheeldAddress),
						new FunctionArg(1,&pinNumber));

}
//Sending message remotely 
void RemoteOneSheeld::sendMessage(const char * key , float value)
{
	OneSheeld.sendPacket(REMOTE_SHEELD_ID,0,REMOTEONESHEELD_SEND_FLOAT,3,
						new FunctionArg(strlen(remoteOneSheeldAddress),(byte*)remoteOneSheeldAddress),
						new FunctionArg(strlen(key),(byte*)key),
						new FunctionArg(4,(byte*)OneSheeld.convertFloatToBytes(value)));
}
//Supporting Strings for arduino
#if !defined(ARDUINO_LINUX) 
void RemoteOneSheeld::sendMessage(String key , float value)
{
	const char * ctypeKey = key.c_str();

	sendMessage(ctypeKey,value);
}

void RemoteOneSheeld::sendMessage(String key , String stringData)
{
	const char * ctypeKey = key.c_str();
	const char * ctypeData = stringData.c_str();

	sendMessage(ctypeKey,ctypeData);
}
#endif
//Supporting Strings for Arduino 
#if defined(ARDUINO_LINUX)
void RemoteOneSheeld::sendMessage(String key , float value)
{
	int keyLength = key.length();

	char ctypeKey[keyLength+1];

	for(int i= 0 ; i<keyLength ;i++)
	{
		ctypeKey[i]=key[i];
	}
	ctypeKey[keyLength]='\0';

	sendMessage(ctypeKey,value);
}

void RemoteOneSheeld::sendMessage(String key , String stringData)
{
	int keyLength = key.length();
	int stringDataLength = stringData.length();

	char ctypeKey[keyLength+1];
	char ctypeStringData[stringDataLength+1];

	for(int i= 0 ;i<keyLength;i++)
	{
		ctypeKey[i]=key[i];
	}
	ctypeKey[keyLength]='\0';

	for(int j= 0 ;j<stringDataLength;j++)
	{
		ctypeStringData[j]=stringData[j];
	}
	ctypeStringData[stringDataLength]='\0';

	sendMessage(ctypeKey,ctypeStringData);
}
#endif
//Sending message remotely 
void RemoteOneSheeld::sendMessage(const char * key , const char * stringData)
{
	OneSheeld.sendPacket(REMOTE_SHEELD_ID,0,REMOTEONESHEELD_SEND_STRING,3,
						new FunctionArg(strlen(remoteOneSheeldAddress),(byte*)remoteOneSheeldAddress),
						new FunctionArg(strlen(key),(byte*)key),
						new FunctionArg(strlen(stringData),(byte*)stringData));
}
//Getting Data from remote 1Sheeld
void RemoteOneSheeld::setOnNewMessage(void (*userFunction)(char key [], float value))
{
	changeFloatCallBack=userFunction;
	isFloatMessageAssigned = true;
}
//Getting Data from remote 1Sheeld 
void RemoteOneSheeld::setOnNewMessage(void (*userFunction)(String key, float value))
{
	changeFloatCallBackString=userFunction;
	usedSetOnFloatWithString= true;
}
//Getting Data from remote 1Sheeld
void RemoteOneSheeld::setOnNewMessage(void (*userFunction)(char key[], char stringData[]))
{
	changeStringCallBack=userFunction;
	isStringMessageAssigned = true;
}
//Getting Data from remote 1Sheeld
void RemoteOneSheeld::setOnNewMessage(void (*userFunction)(String key, String stringData))
{
	changeStringCallBackString=userFunction;
	usedSetOnStringWithString = true;
}
//Getting Data from remote 1Sheeld
void RemoteOneSheeld::setOnSubscribeOrDigitalChange(void (* userFunction)(byte incommingPinNumber,bool incommingPinValue))
{
	changeSubscribeOrDigitalCallBack=userFunction;
	isSubscribeAssigned=true;
}
//Subscribe to a certain pin on remote arduino 
void RemoteOneSheeld::subscribeToChanges(byte pin0)
{
	pin0 = checkAnalogPinNumbers(pin0);

	OneSheeld.sendPacket(REMOTE_SHEELD_ID,0,REMOTEONESHEELD_SUBSCRIBE,2,
						 new FunctionArg(strlen(remoteOneSheeldAddress),(byte*)remoteOneSheeldAddress),
						 new FunctionArg(1,&pin0));
}

//Subscribe to a certain pin on remote arduino 
void RemoteOneSheeld::subscribeToChanges(byte pin0 ,byte pin1)
{
	pin0 = checkAnalogPinNumbers(pin0);
	pin1 = checkAnalogPinNumbers(pin1);

	OneSheeld.sendPacket(REMOTE_SHEELD_ID,0,REMOTEONESHEELD_SUBSCRIBE,3,
						 new FunctionArg(strlen(remoteOneSheeldAddress),(byte*)remoteOneSheeldAddress),
						 new FunctionArg(1,&pin0),
						 new FunctionArg(1,&pin1));
}

//Subscribe to a certain pin on remote arduino 
void RemoteOneSheeld::subscribeToChanges(byte pin0 ,byte pin1,byte pin2)
{
	pin0 = checkAnalogPinNumbers(pin0);
	pin1 = checkAnalogPinNumbers(pin1);
	pin2 = checkAnalogPinNumbers(pin2);

	OneSheeld.sendPacket(REMOTE_SHEELD_ID,0,REMOTEONESHEELD_SUBSCRIBE,4,
						 new FunctionArg(strlen(remoteOneSheeldAddress),(byte*)remoteOneSheeldAddress),
						 new FunctionArg(1,&pin0),
						 new FunctionArg(1,&pin1),
						 new FunctionArg(1,&pin2));
}

//Subscribe to a certain pin on remote arduino 
void RemoteOneSheeld::subscribeToChanges(byte pin0 ,byte pin1,byte pin2,byte pin3)
{
	pin0 = checkAnalogPinNumbers(pin0);
	pin1 = checkAnalogPinNumbers(pin1);
	pin2 = checkAnalogPinNumbers(pin2);
	pin3 = checkAnalogPinNumbers(pin3);

	OneSheeld.sendPacket(REMOTE_SHEELD_ID,0,REMOTEONESHEELD_SUBSCRIBE,5,
						 new FunctionArg(strlen(remoteOneSheeldAddress),(byte*)remoteOneSheeldAddress),
						 new FunctionArg(1,&pin0),
						 new FunctionArg(1,&pin1),
						 new FunctionArg(1,&pin2),
						 new FunctionArg(1,&pin3));
}

//Subscribe to a certain pin on remote arduino 
void RemoteOneSheeld::subscribeToChanges(byte pin0 ,byte pin1,byte pin2,byte pin3 ,byte pin4)
{
	pin0 = checkAnalogPinNumbers(pin0);
	pin1 = checkAnalogPinNumbers(pin1);
	pin2 = checkAnalogPinNumbers(pin2);
	pin3 = checkAnalogPinNumbers(pin3);
	pin4 = checkAnalogPinNumbers(pin4);

	OneSheeld.sendPacket(REMOTE_SHEELD_ID,0,REMOTEONESHEELD_SUBSCRIBE,6,
						 new FunctionArg(strlen(remoteOneSheeldAddress),(byte*)remoteOneSheeldAddress),
						 new FunctionArg(1,&pin0),
						 new FunctionArg(1,&pin1),
						 new FunctionArg(1,&pin2),
						 new FunctionArg(1,&pin3),
						 new FunctionArg(1,&pin4));
}

//unSubscribe to a certain pin on remote arduino 
void RemoteOneSheeld::unSubscribeToChanges(byte pin0)
{
	pin0 = checkAnalogPinNumbers(pin0);

	OneSheeld.sendPacket(REMOTE_SHEELD_ID,0,REMOTEONESHEELD_UNSUBSCRIBE,2,
						 new FunctionArg(strlen(remoteOneSheeldAddress),(byte*)remoteOneSheeldAddress),
						 new FunctionArg(1,&pin0));
}

//unSubscribe to a certain pin on remote arduino 
void RemoteOneSheeld::unSubscribeToChanges(byte pin0 ,byte pin1)
{
	pin0 = checkAnalogPinNumbers(pin0);
	pin1 = checkAnalogPinNumbers(pin1);
	
	OneSheeld.sendPacket(REMOTE_SHEELD_ID,0,REMOTEONESHEELD_UNSUBSCRIBE,3,
						 new FunctionArg(strlen(remoteOneSheeldAddress),(byte*)remoteOneSheeldAddress),
						 new FunctionArg(1,&pin0),
						 new FunctionArg(1,&pin1));
}

//unSubscribe to a certain pin on remote arduino 
void RemoteOneSheeld::unSubscribeToChanges(byte pin0 ,byte pin1,byte pin2)
{
	pin0 = checkAnalogPinNumbers(pin0);
	pin1 = checkAnalogPinNumbers(pin1);
	pin2 = checkAnalogPinNumbers(pin2);

	OneSheeld.sendPacket(REMOTE_SHEELD_ID,0,REMOTEONESHEELD_UNSUBSCRIBE,4,
						 new FunctionArg(strlen(remoteOneSheeldAddress),(byte*)remoteOneSheeldAddress),
						 new FunctionArg(1,&pin0),
						 new FunctionArg(1,&pin1),
						 new FunctionArg(1,&pin2));
}

//unSubscribe to a certain pin on remote arduino 
void RemoteOneSheeld::unSubscribeToChanges(byte pin0 ,byte pin1,byte pin2,byte pin3)
{
	pin0 = checkAnalogPinNumbers(pin0);
	pin1 = checkAnalogPinNumbers(pin1);
	pin2 = checkAnalogPinNumbers(pin2);
	pin3 = checkAnalogPinNumbers(pin3);

	OneSheeld.sendPacket(REMOTE_SHEELD_ID,0,REMOTEONESHEELD_UNSUBSCRIBE,5,
						 new FunctionArg(strlen(remoteOneSheeldAddress),(byte*)remoteOneSheeldAddress),
						 new FunctionArg(1,&pin0),
						 new FunctionArg(1,&pin1),
						 new FunctionArg(1,&pin2),
						 new FunctionArg(1,&pin3));
}

//unSubscribe to a certain pin on remote arduino 
void RemoteOneSheeld::unSubscribeToChanges(byte pin0 ,byte pin1,byte pin2,byte pin3 ,byte pin4)
{
	pin0 = checkAnalogPinNumbers(pin0);
	pin1 = checkAnalogPinNumbers(pin1);
	pin2 = checkAnalogPinNumbers(pin2);
	pin3 = checkAnalogPinNumbers(pin3);
	pin4 = checkAnalogPinNumbers(pin4);

	OneSheeld.sendPacket(REMOTE_SHEELD_ID,0,REMOTEONESHEELD_UNSUBSCRIBE,6,
						 new FunctionArg(strlen(remoteOneSheeldAddress),(byte*)remoteOneSheeldAddress),
						 new FunctionArg(1,&pin0),
						 new FunctionArg(1,&pin1),
						 new FunctionArg(1,&pin2),
						 new FunctionArg(1,&pin3),
						 new FunctionArg(1,&pin4));
}
//Process Input data from remote 1Sheeld
void RemoteOneSheeld::processFrame()
{
	if(!(isSubscribeAssigned || isFloatMessageAssigned || usedSetOnFloatWithString || usedSetOnStringWithString || isStringMessageAssigned) || OneSheeld.isInACallback())
		return;

	if(memcmp (remoteOneSheeldAddress,OneSheeld.getArgumentData(0),36))return;

	byte functionId = OneSheeld.getFunctionId();

	OneSheeld.enteringACallback();
	if(functionId == DIGITAL_SUBSCRIBE_VALUE && isSubscribeAssigned)
	{
		int argumentNo = OneSheeld.getArgumentNo();
		byte pinData;
		byte pinNo;
		bool pinValue;
		for (int i=1 ; i <argumentNo;i++)
		{
			pinData = OneSheeld.getArgumentData(i)[0];
			pinNo = pinData & 0x7F;
			pinValue = !!(pinData >> 7);

			(*changeSubscribeOrDigitalCallBack)(pinNo,pinValue);
		}
	}
	else if(functionId == READ_MESSAGE_FLOAT)
	{
    	int floatKeyLength = OneSheeld.getArgumentLength(1);
    	char floatKey[floatKeyLength+1];
    	memcpy(floatKey,OneSheeld.getArgumentData(1),floatKeyLength);
    	floatKey[floatKeyLength]='\0';

    	float incommingFloatValue=OneSheeld.convertBytesToFloat(OneSheeld.getArgumentData(2));

    	if(usedSetOnFloatWithString)
    	{
    		String floatKeyInString(floatKey);
    		(*changeFloatCallBackString)(floatKeyInString,incommingFloatValue);
    	}
    	if(isFloatMessageAssigned)
    	{
    		(*changeFloatCallBack)(floatKey,incommingFloatValue);	
    	}
		

	}
	else if(functionId == READ_MESSAGE_STRING )
	{
		int stringKeyLength = OneSheeld.getArgumentLength(1);
    	char stringKey[stringKeyLength+1];
    	memcpy(stringKey,OneSheeld.getArgumentData(1),stringKeyLength);
    	stringKey[stringKeyLength]='\0';

    	int stringDataLength=OneSheeld.getArgumentLength(2);
    	char incommingStringData[stringDataLength+1];
    	memcpy(incommingStringData,OneSheeld.getArgumentData(2),stringDataLength);
   	 	incommingStringData[stringDataLength]='\0';

   	 	if(usedSetOnStringWithString)
    	{
    		String stringKeyInString(stringKey);
    		String incommingStringDataInString(incommingStringData);
    		(*changeStringCallBackString)(stringKeyInString,incommingStringDataInString);
    	}
    	if(isStringMessageAssigned)
    	{
    		(*changeStringCallBack)(stringKey,incommingStringData);	
    	}
	}
	OneSheeld.exitingACallback();
}
//Check analog pins low level number 
byte RemoteOneSheeld::checkAnalogPinNumbers(byte pinNumber)
{
	switch(pinNumber)
	{
		case A0:pinNumber=14;break;
		case A1:pinNumber=15;break;
		case A2:pinNumber=16;break;
		case A3:pinNumber=17;break;
		case A4:pinNumber=18;break;
		case A5:pinNumber=19;break;
		default : return pinNumber;
	}
	return pinNumber;
}
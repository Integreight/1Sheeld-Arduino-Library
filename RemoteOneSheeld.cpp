#include "OneSheeld.h"
#include "RemoteOneSheeld.h"






RemoteOneSheeld::RemoteOneSheeld(const char * address):remoteOneSheeldAddress(address)
{
	isCallBackAssigned=false;
	isFloatMessageAssigned=false;
	isStringMessageAssigned=false;
	isSubscribeAssigned=false;
}

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

void RemoteOneSheeld::digitalRead(byte pinNumber , void (* userFunction)(byte incommingPinNumber,bool incommingPinValue))
{
	OneSheeld.sendPacket(REMOTE_SHEELD_ID,0,REMOTEONESHEELD_READ,2,
						new FunctionArg(strlen(remoteOneSheeldAddress),(byte*)remoteOneSheeldAddress),
						new FunctionArg(1,&pinNumber));

	changeDigitalCallBack=userFunction;
	isCallBackAssigned=true;
}

void RemoteOneSheeld::sendMessage(const char * key , float value)
{
	OneSheeld.sendPacket(REMOTE_SHEELD_ID,0,REMOTEONESHEELD_SEND_FLOAT,3,
						new FunctionArg(strlen(remoteOneSheeldAddress),(byte*)remoteOneSheeldAddress),
						new FunctionArg(strlen(key),(byte*)key),
						new FunctionArg(sizeof(float),(byte*)OneSheeld.convertFloatToBytes(value)));
}

void RemoteOneSheeld::sendMessage(const char * key , const char * stringData)
{
	OneSheeld.sendPacket(REMOTE_SHEELD_ID,0,REMOTEONESHEELD_SEND_STRING,3,
						new FunctionArg(strlen(remoteOneSheeldAddress),(byte*)remoteOneSheeldAddress),
						new FunctionArg(strlen(key),(byte*)key),
						new FunctionArg(strlen(stringData),(byte*)stringData));
}

void RemoteOneSheeld::setOnFloatMessage(void (*userFunction)(char* key, float value))
{
	changeFloatCallBack=userFunction;
	isFloatMessageAssigned = true;
}

void RemoteOneSheeld::setOnStringMessage(void (*userFunction)(char* key, char* stringData))
{
	changeStringCallBack=userFunction;
	isStringMessageAssigned = true;
}

void RemoteOneSheeld::setOnSubscribeChange(void (* userFunction)(byte incommingPinNumber,bool incommingPinValue))
{
	changeSubscribeCallBack=userFunction;
	isSubscribeAssigned=true;
}

void RemoteOneSheeld::subscribeToChanges(byte pin0)
{
	pin0 = checkAnalogPinNumbers(pin0);

	OneSheeld.sendPacket(REMOTE_SHEELD_ID,0,REMOTEONESHEELD_SUBSCRIBE,2,
						 new FunctionArg(strlen(remoteOneSheeldAddress),(byte*)remoteOneSheeldAddress),
						 new FunctionArg(1,&pin0));
}

void RemoteOneSheeld::subscribeToChanges(byte pin0 ,byte pin1)
{
	pin0 = checkAnalogPinNumbers(pin0);
	pin1 = checkAnalogPinNumbers(pin1);

	OneSheeld.sendPacket(REMOTE_SHEELD_ID,0,REMOTEONESHEELD_SUBSCRIBE,3,
						 new FunctionArg(strlen(remoteOneSheeldAddress),(byte*)remoteOneSheeldAddress),
						 new FunctionArg(1,&pin0),
						 new FunctionArg(1,&pin1));
}

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

void RemoteOneSheeld::unSubscribeToChanges(byte pin0)
{
	pin0 = checkAnalogPinNumbers(pin0);

	OneSheeld.sendPacket(REMOTE_SHEELD_ID,0,REMOTEONESHEELD_UNSUBSCRIBE,2,
						 new FunctionArg(strlen(remoteOneSheeldAddress),(byte*)remoteOneSheeldAddress),
						 new FunctionArg(1,&pin0));
}

void RemoteOneSheeld::unSubscribeToChanges(byte pin0 ,byte pin1)
{
	pin0 = checkAnalogPinNumbers(pin0);
	pin1 = checkAnalogPinNumbers(pin1);
	
	OneSheeld.sendPacket(REMOTE_SHEELD_ID,0,REMOTEONESHEELD_UNSUBSCRIBE,3,
						 new FunctionArg(strlen(remoteOneSheeldAddress),(byte*)remoteOneSheeldAddress),
						 new FunctionArg(1,&pin0),
						 new FunctionArg(1,&pin1));
}

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

void RemoteOneSheeld::processData()
{
	if(memcmp (remoteOneSheeldAddress,OneSheeld.getArgumentData(0),36))return;

	byte functionId = OneSheeld.getFunctionId();

	if(functionId == DIGITAL_READ_VALUE)
	{
		byte inputPinNumber;
		byte inputPinValue;

		inputPinNumber = OneSheeld.getArgumentData(1)[0];

		inputPinValue = OneSheeld.getArgumentData(2)[0];

		if(isCallBackAssigned)
		{
			(*changeDigitalCallBack)(inputPinNumber,!!(inputPinValue));
		}

	}
	else if(functionId == READ_MESSAGE_FLOAT)
	{
		if(floatKey!=0)
		{
			free(floatKey);
		}

		int floatKeyLength=OneSheeld.getArgumentLength(1);
		floatKey = (char*)malloc(sizeof(char)*(floatKeyLength+1));
		for (int j=0; j<floatKeyLength; j++)
		{
			floatKey[j]=OneSheeld.getArgumentData(1)[j];
		}
		floatKey[floatKeyLength]='\0';

		incommingFloatValue=OneSheeld.convertBytesToFloat(OneSheeld.getArgumentData(2));

		if(isFloatMessageAssigned)
		{
			(*changeFloatCallBack)(floatKey,incommingFloatValue);
		}

	}
	else if(functionId == READ_MESSAGE_STRING)
	{
		if(stringKey!=0)
		{
			free(stringKey);
		}

		if(incommingStringData!=0)
		{
			free(incommingStringData);
		}

		int stringKeyLength=OneSheeld.getArgumentLength(1);
		stringKey = (char*)malloc(sizeof(char)*(stringKeyLength+1));
		for (int j=0; j<stringKeyLength; j++)
		{
			stringKey[j]=OneSheeld.getArgumentData(1)[j];
		}
		stringKey[stringKeyLength]='\0';

		int stringDataLength=OneSheeld.getArgumentLength(2);
		incommingStringData = (char*)malloc(sizeof(char)*(stringDataLength+1));
		for (int i=0; i<stringDataLength; i++)
		{
			incommingStringData[i]=OneSheeld.getArgumentData(2)[i];
		}
		incommingStringData[stringDataLength]='\0';


		if(isStringMessageAssigned)
		{
			(*changeStringCallBack)(stringKey,incommingStringData);
		}

	}
	else if(functionId == SUBSCRIBE_VALUE)
	{
		int argumentNo = OneSheeld.getArgumentNo();
		byte pinData;
		byte pinNo;
		bool pinValue;

		for (int i=1 ; i <argumentNo-1;i++)
		{
			pinData = OneSheeld.getArgumentData(i)[0];
			pinNo = pinData & 0x7F;
			pinValue = !!(pinData >> 7);

			(*changeSubscribeCallBack)(pinNo,pinValue);
		}
	}
}

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
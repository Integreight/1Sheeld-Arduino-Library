/*

  Project:       1Sheeld Library 
  File:          RemoteOneSheeld.h
                 
  Version:       1.3

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.12

*/

#ifndef RemoteOneSheeld_h
#define RemoteOneSheeld_h

//Output function ID's 
#define REMOTEONESHEELD_PIN_MODE 	 0x01
#define REMOTEONESHEELD_WRITE 		 0x02
#define REMOTEONESHEELD_READ  		 0x03
#define REMOTEONESHEELD_ANALOG_WRITE 0x04
#define REMOTEONESHEELD_SEND_FLOAT	 0x05
#define REMOTEONESHEELD_SEND_STRING	 0x06
#define REMOTEONESHEELD_SUBSCRIBE	 0x07
#define REMOTEONESHEELD_UNSUBSCRIBE  0x08

//Input function ID's
#define DIGITAL_SUBSCRIBE_VALUE	 0x01
#define READ_MESSAGE_FLOAT 		 0x02
#define READ_MESSAGE_STRING 	 0x03


class RemoteOneSheeld
{
friend class OneSheeldClass;

public:
	//Constructor
	RemoteOneSheeld(const char*);
	//Setters
	void pinMode(byte ,byte);
	void digitalWrite(byte ,byte);
	void digitalRead(byte);
	void analogWrite(byte ,int);
	//Senders
	void sendMessage(const char* ,float);
	void sendMessage(String , float);
	void sendMessage(const char* ,const char*);
	void sendMessage(String ,String );
	//Getters
	void setOnNewMessage(void (*)(char*,float));
	void setOnNewMessage(void (*)(String , float));
	void setOnNewMessage(void(*)(char* , char*));
	void setOnNewMessage(void(*)(String , String));
	void setOnSubscribeOrDigitalChange(void (*)(byte , bool));
	//Subscribers
	void subscribeToChanges(byte);
	void subscribeToChanges(byte ,byte);
	void subscribeToChanges(byte ,byte ,byte);
	void subscribeToChanges(byte ,byte ,byte , byte);
	void subscribeToChanges(byte ,byte ,byte , byte, byte);
	//Unsubscribers
	void unSubscribeToChanges(byte);
	void unSubscribeToChanges(byte ,byte);
	void unSubscribeToChanges(byte ,byte ,byte);
	void unSubscribeToChanges(byte ,byte ,byte , byte);
	void unSubscribeToChanges(byte ,byte ,byte , byte, byte);

private:
	//Reserved for Data
	const char * remoteOneSheeldAddress;
	char * floatKey;
	char * stringKey;
	char * incommingStringData;
	float incommingFloatValue;
	//Booleans
	bool isFloatMessageAssigned;
	bool isStringMessageAssigned;
	bool isSubscribeAssigned;
	bool usedSetOnFloatWithString;
	bool usedSetOnStringWithString;
	//Functions
	void processData();
	//Set On Change for user functions
	void (*changeFloatCallBack)(char*, float);
	void (*changeFloatCallBackString)(String ,float);
	void (*changeStringCallBack)(char*, char*);
	void (*changeStringCallBackString)(String ,String);
	void (*changeSubscribeOrDigitalCallBack)(byte ,bool);
	//Checker
	byte checkAnalogPinNumbers(byte);

};
#endif
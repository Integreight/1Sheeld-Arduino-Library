/*

  Project:       1Sheeld Library 
  File:          OneSheeld.h
                 
  Version:       1.2

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/

#ifndef OneSheeld_h
#define OneSheeld_h
#include "Stream.h"
#include "Arduino.h"


typedef unsigned char byte;

#include "IncludedShieldsDefines.h"
#include "ShieldsIncludes.h"
#include "ShieldsIds.h"

#define ONE_SECOND 1000

//#define ONESHEELD_BEGIN 0x01

//Start and End of packet sent
#define START_OF_FRAME  0xFF
#define END_OF_FRAME 	0x00
//Library Version
#define LIBRARY_VERSION 4
//Time between sending Frames
#define TIME_GAP		200UL
//Maximum number of remote connections
#define MAX_REMOTE_CONNECTIONS 10

//Selecting picture from folder
#define FROM_ONESHEELD_FOLDER 0x00
#define FROM_CAMERA_FOLDER	  0x01

//#define DEBUG

//Output function ID's
#define SEND_LIBRARY_VERSION	0x01
#define WAIT_RESET_APPLICATION	0x02
//Input function ID's 
//Checking Bluetooth connection
#define CONNECTION_CHECK_FUNCTION 0x01
#define DISCONNECTION_CHECK_FUNCTION 0x02
#define LIBRARY_VERSION_REQUEST	0x03



//Class for Datalength and Data
class FunctionArg
{
private:
	byte length;
	byte * data;
public:
	FunctionArg(int l ,byte * d)
	{
		length=(l>0xff)?0xff:l;
		data=d;
	}
	byte getLength()
	{
		return length;
	}
	byte * getData()
	{
		return data;
	}

};

union FloatUnion{
	    float number;
	    byte floatBytes[sizeof(float)];
	  };



class OneSheeldClass
{


public:
    
	OneSheeldClass(Stream &s);
	//Blocking function
	void waitForAppConnection();
	//Check connection
	bool isAppConnected();
	//Getters 
	byte getShieldId();
	byte getInstanceId();
	byte getFunctionId();
	byte getArgumentNo();
	byte getArgumentLength(byte );
	byte * getArgumentData(byte );
	byte * convertFloatToBytes(float );
	float convertBytesToFloat(byte * );
	void listenToRemoteOneSheeld(RemoteOneSheeld *);
	//Processing Incomming Frames
	void processInput();		
	//Library Starter
	void begin();
	//Frame Sender
	void sendPacket(byte shieldID, byte instanceID,byte functionCommand, byte argNo, ...);
	//PulseWidthModulation Getter 
	unsigned char analogRead(int );
	//Set on change for users function
	void setOnNewMessage(void (*)(char * ,char * ,float));
	void setOnNewMessage(void (*)(String ,String ,float));
	void setOnNewMessage(void (*)(char * ,char * ,char *));
	void setOnNewMessage(void (*)(String  ,String ,String ));	 
	Stream & OneSheeldSerial;

private:
	//Reserve Variables
	FloatUnion convertFloatUnion;
	bool isArgumentsNumberMalloced;
	bool isArgumentLengthMalloced;
	bool isOneSheeldConnected;
	bool isFirstFrame;
	bool framestart;
	//Remote OneSheeld fnuctions
	bool isSetOnFloatMessageInvoked;
	bool isSetOnStringMessageInvoked;
	bool usedSetOnFloatWithString;
	bool usedSetOnStringWithString;
	bool isOneSheeldRemoteDataUsed;
	//Data bytes
	byte numberOfDataMalloced;
	byte shield;
	byte instance;
	byte functions;
	byte counter;
	byte argumentcounter;
	byte datalengthcounter;
	byte argumentnumber;
	byte **arguments;	
	byte *argumentL;            
	byte endFrame;
	//Checker variable 
	unsigned long lastTimeFrameSent;
	//Number of connected Remote 1Sheelds
	int remoteOneSheeldsCounter;
	//Array of remote 1Sheelds
	RemoteOneSheeld * listOfRemoteOneSheelds[MAX_REMOTE_CONNECTIONS];
	//Send Incomming Data to shields
	void sendToShields();
	void begin(long baudRate);
	void freeMemoryAllocated();
	void processData();
	//Remote OneSheeld fucntions
	void processRemoteData();
	void (*changeFloatCallBack)(char*,char*, float);
	void (*changeFloatCallBackWithString)(String ,String , float);
	void (*changeStringCallBack)(char*,char*, char*);
	void (*changeStringCallBackWithString)(String ,String ,String );
};


//Extern Object
extern OneSheeldClass OneSheeld;
#endif
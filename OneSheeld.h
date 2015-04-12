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
#include "ShieldsIds.h"
#include "ShieldsSelection.h"
#include "ShieldsIncludes.h"
#include "ShieldParent.h"
#include "ShieldsInstantiation.h"


#define ONE_SECOND 1000

//#define ONESHEELD_BEGIN 0x01

//Start and End of packet sent
#define START_OF_FRAME  0xFF
#define END_OF_FRAME 	0x00
//Library Version
#define LIBRARY_VERSION 5
//Time between sending Frames
#define TIME_GAP		200UL

#ifdef REMOTE_SHIELD
//Maximum number of remote connections
#define MAX_REMOTE_CONNECTIONS 10
#endif

//Selecting picture from folder
#define FROM_ONESHEELD_FOLDER 0x00
#define FROM_CAMERA_FOLDER	  0x01

// #define DEBUG

//Output function ID's
#define SEND_LIBRARY_VERSION	0x01
#define CHECK_APP_CONNECTION	0x02
#define CALLBACK_ENTERED		0x03
#define CALLBACK_EXITED			0x04
//Input function ID's 
//Checking Bluetooth connection
#define CONNECTION_CHECK_FUNCTION 0x01
#define DISCONNECTION_CHECK_FUNCTION 0x02
#define LIBRARY_VERSION_REQUEST	0x03


//Numer of Shields
#define SHIELDS_NO	40

//Class for Datalength and Data
class FunctionArg
{
private:
	byte length;
	byte * data;
	bool saveData;
public:
	FunctionArg(int l ,byte * d, bool _saveData=false)
	{
		saveData=_saveData;
		length=(l>0xff)?0xff:l;
		if(saveData)
		{
			data=(byte *)malloc(sizeof(byte)*length);
			memcpy(data,d,length);
		}
		else
		{
			data=d;
		}
	}
	byte getLength()
	{
		return length;
	}
	byte * getData()
	{
		return data;
	}
	~FunctionArg()
	{
		if(saveData)free(data);
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
	void setOnAppConnected(void (*)(bool));
	//Getters 
	byte getShieldId();
	byte getInstanceId();
	byte getFunctionId();
	byte getArgumentNo();
	byte getArgumentLength(byte );
	byte * getArgumentData(byte );
	byte * convertFloatToBytes(float );
	float convertBytesToFloat(byte * );
	#ifdef REMOTE_SHIELD
	void listenToRemoteOneSheeld(RemoteOneSheeld *);
	#endif
	//Processing Incomming Frames
	void processInput();		
	//Library Starter
	void begin();
	//Adding objects in array 
	static void addToShieldsArray(ShieldParent *);
	// #ifdef INTERNET_SHIELD
	static void addToUnSentRequestsArray(HttpRequest *);
	// #endif
	static bool isInitialized();
	//Frame Sender
	void sendPacket(byte , byte ,byte , byte , ...);
	void sendPacket(byte , byte , byte , byte , FunctionArg ** );
	//PulseWidthModulation Getter 
	unsigned char analogRead(int );
	//Set on change for users function
	void setOnNewMessage(void (*)(char  [] ,char [] ,float));
	void setOnNewMessage(void (*)(String ,String ,float));
	void setOnNewMessage(void (*)(char [] ,char [] ,char []));
	void setOnNewMessage(void (*)(String  ,String ,String ));	 
	Stream & OneSheeldSerial;
	void delay(unsigned long);
	bool isCallbacksInterruptsSet();
	void enableCallbacksInterrupts();
	void disableCallbacksInterrupts();
private:
	//Reserve Variables
	FloatUnion convertFloatUnion;
	bool isArgumentsNumberMalloced;
	bool isArgumentLengthMalloced;
	bool isOneSheeldConnected;
	bool isAppConnectionCallBack;
	static bool isFirstFrame;
	bool framestart;
	#ifdef REMOTE_SHIELD
	//Remote OneSheeld fnuctions
	bool isSetOnFloatMessageInvoked;
	bool isSetOnStringMessageInvoked;
	bool usedSetOnFloatWithString;
	bool usedSetOnStringWithString;
	bool isOneSheeldRemoteDataUsed;
	//Number of connected Remote 1Sheelds
	int remoteOneSheeldsCounter;
	#endif
	static bool inACallback;
	static bool callbacksInterrupts;
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
	//Shields Counter 
	static byte shieldsCounter;
	//Requests Counter
	static byte requestsCounter;
	//Is constructor called
	static bool isInit;
	//Checker variable 
	static unsigned long lastTimeFrameSent;
	#ifdef REMOTE_SHIELD
	//Array of remote 1Sheelds
	RemoteOneSheeld * listOfRemoteOneSheelds[MAX_REMOTE_CONNECTIONS];
	#endif
	//Array of pointers to Parents
	static ShieldParent * shieldsArray[SHIELDS_NO];
	// #ifdef INTERNET_SHIELD
	//Array of pointers to un sent requests
	static HttpRequest ** requestsArray;
	// #endif
	//Send Incomming Data to shields
	void sendToShields();
	void begin(long baudRate);
	void freeMemoryAllocated();
	void processFrame();
	#ifdef REMOTE_SHIELD
	//Remote OneSheeld fucntions
	void processRemoteData();
	#endif
	void (*changeFloatCallBack)(char [],char [], float);
	void (*changeFloatCallBackWithString)(String ,String , float);
	void (*changeStringCallBack)(char [],char [], char []);
	void (*changeStringCallBackWithString)(String ,String ,String );
	void (*isAppConnectedCallBack)(bool);
	void enteringACallback();
	void exitingACallback();
	bool isInACallback();
	void processInput(int byte);
friend class RemoteOneSheeld;
friend class ShieldParent;
};


//Extern Object
extern OneSheeldClass OneSheeld;
#endif
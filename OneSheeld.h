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

#define ONESHEELD_BEGIN 0x01

//Start and End of packet sent
#define START_OF_FRAME  0xFF
#define END_OF_FRAME 	0x00
//Library Version
#define LIBRARY_VERSION 3
//Time between sending Frames
#define TIME_GAP		200UL

//#define DEBUG

#define CONNECTION_CHECK_FUNCTION 0x01


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
	void waitForConnection();
	//Getters 
	byte getShieldId();
	byte getInstanceId();
	byte getFunctionId();
	byte getArgumentNo();
	byte getArgumentLength(byte );
	byte * getArgumentData(byte );
	byte * convertFloatToBytes(float );
	float convertBytesToFloat(byte * );
	//Processing Incomming Frames
	void processInput();		
	//Library Starter
	void begin();
	//Frame Sender
	void sendPacket(byte shieldID, byte instanceID,byte functionCommand, byte argNo, ...);
	//PulseWidthModulation Getter 
	unsigned char analogRead(int );
	Stream & OneSheeldSerial;
private:
	//Reserve Variables
	FloatUnion convertFloatUnion;
	bool isArgumentsNumberMalloced;
	bool isArgumentLengthMalloced;
	bool isOneSheeldConnected;
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
	bool framestart;
	byte endFrame;
	unsigned long lastTimeFrameSent;
	bool isFirstFrame;
	unsigned long lastTimeConnectionSent;
	bool didAppRespondToConnectionQuery;
	//Send Incomming Data to shields
	void sendToShields();
	void begin(long baudRate);
	void freeMemoryAllocated();
	void checkAppConnection();
	void processData();
};


//Extern Object
extern OneSheeldClass OneSheeld;
#endif
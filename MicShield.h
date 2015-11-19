/*

  Project:       1Sheeld Library 
  File:          MicShield.h
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/

#ifndef MicShield_h
#define MicShield_h

#include "ShieldParent.h"

//Input Function ID 
#define MIC_VALUE 0x01

//Ouput Function ID's
#define MIC_START_RECORD 	   0x01
#define MIC_STOP_RECORD	   	   0x02

class MicShield : public ShieldParent
{
public:
	//Constructor
	MicShield();
	//Record Starter
	void startRecording();
	void startRecording(const char *);
	void startRecording(String );
	//Record Stop
	void stopRecording();
	//Getter
	byte getValue();
	//setOnChange for Users Function
	void setOnValueChange(void (*)(byte));

private:
	//Reserve Variable
	byte value;
	//Boolean for the setOnChange Function
	bool isCallBackAssigned;
	//Process Input Data  
	void processData();
	void (*changeCallBack)(byte);
};

//Extern Object
extern MicShield Mic;
#endif
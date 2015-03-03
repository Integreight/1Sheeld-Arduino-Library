/*

  Project:       1Sheeld Library 
  File:          VoiceRecognitionShield.h
                 
  Version:       1.2

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.9

*/
#ifndef	VoiceRecognitionShield_h
#define VoiceRecognitionShield_h

#include "ShieldParent.h"

//Output  function ID's
#define VOICE_START_LISTENING	0x01

//Input Function ID's 
#define VOICE_GET 				0x01
#define VOICE_GET_ERROR		    0x02

//Errors messages 
#define NETWORK_TIMEOUT_ERROR	0x01
#define NETWORK_ERROR 			0x02
#define AUDIO_ERROR 			0x03
#define SERVER_ERROR 			0x04
#define SPEECH_TIMEOUT_ERROR	0x06
#define NO_MATCH_ERROR			0x07
#define RECOGNIZER_BUSY_ERROR	0x08


class VoiceRecognitionShield : public ShieldParent
{
public:
	//Constructor 
	VoiceRecognitionShield();
	//Listener
	void start();
	//Getter
	char * getLastCommand();
	//Getter
	String getCommandAsString();
	//Getter
	int getLastCommandLength();
	//Checker 
	bool isNewCommandReceived();
	//Setter
	void setOnNewCommand(void (*)(char []));
	//Setter using Strings 
	void setOnNewCommand(void (*)(String));
	//Setter
	void setOnError(void (*)(byte));

private:
	//Pointer to voice data in memory 
	char * voice;
	//Voice length
	int voicetextLength;
	//Boolean for Users function
	bool isCallBackAssigned;
	bool errorAssigned;
	bool didDataCame;
	bool usedSetOnWithString;
	bool newCommand; 
	//Error number for user function 
	byte errorNumber;
	//Process Input Data
	void processData();
	//Setter 
	void (*changeCallBack)(char*);
	//Setter 
	void (*changeCallBackString)(String);
	//Setter
	void (*errorCallBack)(byte);
};
//Extern Object
extern VoiceRecognitionShield VoiceRecognition;
#endif
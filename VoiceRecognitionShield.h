/*

  Project:       1Sheeld Library 
  File:          VoiceRecognitionShield.h
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/
#ifndef	VoiceRecognitionShield_h
#define VoiceRecognitionShield_h

//Input Function ID's 
#define GET_VOICE 0x01
#define START_LISTENING	0x01


class VoiceRecognitionShield
{
public:
	//Constructor 
	VoiceRecognitionShield();
	//Listener
	void startListening();
	//Getter
	char * getLastCommand();
	//Checker 
	bool isNewCommandReceived();
	//Setter
	void setOnNewCommand(void (*)(char*));
	//Setter
	void setOnError(void (*)(byte));
private:
	//Pointer to voice data in memory 
	char * voice;
	//Boolean for Users function
	bool isCallBackAssigned;
	//Boolean for Users function
	bool errorAssigned;
	//Error number for user function 
	byte errorNumber;
	//Boolean for newCommand function
	bool newCommand; 
	//Process Input Data
	void processData();
	//Setter 
	void (*changeCallBack)(char*);
	//Setter
	void (*errorCallBack)(byte);
	//Friend Class to OneSheeld Class
	friend class OneSheeldClass;
};
//Extern Object
extern VoiceRecognitionShield VoiceRecognition;
#endif
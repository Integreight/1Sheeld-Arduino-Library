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


#define GET_VOICE 0x01
#define START_LISTENING	0x01


class VoiceRecognitionShield
{
public:
	VoiceRecognitionShield();
	void startListening();
	char * getLastCommand();
	bool isNewCommandReceived();
	void setOnNewCommand(void (*)(char*));
	void setOnError(void (*)(byte));
private:
	char * voice;
	bool isCallBackAssigned;
	bool errorAssigned;
	byte errorNumber;
	bool newCommand; 
	void processData();
	void (*changeCallBack)(char*);
	void (*errorCallBack)(byte);

	friend class OneSheeldClass;
};

extern VoiceRecognitionShield VoiceRecognition;
#endif
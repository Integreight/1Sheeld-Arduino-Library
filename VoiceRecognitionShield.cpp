/*

  Project:       1Sheeld Library 
  File:          VoiceRecognitionShield.cpp
                 
  Version:       1.0.1

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.7

*/
#include "OneSheeld.h"
#include "VoiceRecognitionShield.h"


//Constructor 
VoiceRecognitionShield::VoiceRecognitionShield()
{
	voice =0;
	isCallBackAssigned=false;
	newCommand=false;
	errorAssigned=false;
}
//Start Listen the voice command  
void VoiceRecognitionShield::startListening()
{
	OneSheeld.sendPacket(VOICE_RECOGNITION_ID,0,START_LISTENING,0);
}
//Get and save the voice command
char * VoiceRecognitionShield::getLastCommand()
{
	newCommand=false;
	return voice;
}
//Check if new voice command received
bool VoiceRecognitionShield::isNewCommandReceived()
{
	return newCommand;
}
//Process Input Data
void VoiceRecognitionShield::processData()
{
	byte functionID = OneSheeld.getFunctionId();

	if(functionID==GET_VOICE)
	{
		if (voice!=0)
		{
			free(voice);
		}
		int voicetextLength=OneSheeld.getArgumentLength(0);
		voice = (char*)malloc(sizeof(char)*(voicetextLength+1));
		for (int j=0; j<voicetextLength; j++)
		{
			voice[j]=OneSheeld.getArgumentData(0)[j];
		}
		voice[voicetextLength]='\0';

		
		newCommand=true;

		//Invoke Users function
		if(isCallBackAssigned)
		{
			(*changeCallBack)(voice);
		}

	}
	else if(functionID==GET_ERROR)
	{
		errorNumber=OneSheeld.getArgumentData(1)[0];

		//Invoke User Function
		if(errorAssigned)
		{
			(*errorCallBack)(errorNumber);
		}
	}
}
//Users Function Setter 
void VoiceRecognitionShield::setOnNewCommand(void (*userFunction)(char * voice))
{
	changeCallBack=userFunction;
	isCallBackAssigned=true;
}

void VoiceRecognitionShield::setOnError(void (*userFunction)(byte error))
{
	errorCallBack=userFunction;
	errorAssigned=true;
}


VoiceRecognitionShield VoiceRecognition;
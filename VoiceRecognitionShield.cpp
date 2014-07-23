/*

  Project:       1Sheeld Library 
  File:          VoiceRecognitionShield.cpp
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/



#include "OneSheeld.h"
#include "VoiceRecognitionShield.h"



VoiceRecognitionShield::VoiceRecognitionShield()
{
	voice =0;
	isCallBackAssigned=false;
	newCommand=false;
	errorAssigned=false;
}

void VoiceRecognitionShield::startListening()
{
	OneSheeld.sendPacket(VOICE_RECOGNITION_ID,0,START_LISTENING,0);
}

char * VoiceRecognitionShield::getLastCommand()
{
	return voice;
	newCommand=false;
}

bool VoiceRecognitionShield::isNewCommandReceived()
{
	return newCommand;
}
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

		errorNumber=OneSheeld.getArgumentData(1)[0];
		
		newCommand=true;

		if(isCallBackAssigned)
		{
			(*changeCallBack)(voice);
		}

		if(errorAssigned)
		{
			(*errorCallBack)(errorNumber);
		}
	}
}

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
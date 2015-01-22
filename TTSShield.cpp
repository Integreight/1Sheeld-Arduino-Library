/*

  Project:       1Sheeld Library 
  File:          TTSShield.cpp
                 
  Version:       1.2

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.9

*/
#include "TTSShield.h"

//Give text to be said by the phone
void TTSShield::say(const char * text)
{
	OneSheeld.sendPacket(TTS_ID,0,TTS_SAY,1,new FunctionArg(strlen(text),(byte*)text));
}

//Support string for Arduino
#if !defined(ARDUINO_LINUX)
void TTSShield::say(String text)
{
	const char * cTypeText = text.c_str();

	say(cTypeText);
}
#endif

//Support string for galileo 
#if defined(ARDUINO_LINUX)
void TTSShield::say(String text)
{
	int textLength = text.length();

	char cTypeText[textLength+1];

	for (int i = 0; i <textLength; i++)
	{
		cTypeText[i]=text[i];
	}
	cTypeText[textLength]='\0';

	say(cTypeText);
}
#endif

//Instantiaing Object
TTSShield TextToSpeech;
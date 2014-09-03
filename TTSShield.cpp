/*

  Project:       1Sheeld Library 
  File:          TTSShield.cpp
                 
  Version:       1.2

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.9

*/

#include "OneSheeld.h"
#include "TTSShield.h"



//Give text to be said by the phone
void TTSShield::say(const char * text)
{
	OneSheeld.sendPacket(TTS_ID,0,TTS_SAY,1,new FunctionArg(strlen(text),(byte*)text));
}

//Instantiaing Object
TTSShield TextToSpeech;
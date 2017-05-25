/*

  Project:       1Sheeld Library 
  File:          TTSShield.cpp
                 
  Version:       1.2

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.9

*/
#define FROM_ONESHEELD_LIBRARY
#include "OneSheeld.h"
#include "TTSShield.h"

//Give text to be said by the phone
void TTSShield::say(const char * text)
{
	//Check length of string 
	int textLength = strlen(text);
	if(!textLength) return;
	OneSheeld.sendShieldFrame(TTS_ID,0,TTS_SAY,1,new FunctionArg(textLength,(byte*)text));
}

void TTSShield::say(String text)
{
	say(&text[0]);
}


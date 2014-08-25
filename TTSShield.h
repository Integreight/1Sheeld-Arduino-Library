/*

  Project:       1Sheeld Library 
  File:          TTSShield.h
                 
  Version:       3.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.7

*/

#ifndef TTSShield_h
#define TTSShield_h


#define TTS_SAY 0x01

  class TTSShield
  {
  public:
    //Process
  	void say(const char *);

  private:

  };

  //Extern Object
  extern TTSShield TextToSpeech ;
  #endif
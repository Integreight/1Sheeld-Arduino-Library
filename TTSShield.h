/*

  Project:       1Sheeld Library 
  File:          TTSShield.h
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/

#ifndef TTSShield_h
#define TTSShield_h


#define SEND_TEXT 0x01

  class TTSShield
  {
  public:
  	void say(char *);
  	

  private:

  };

  extern TTSShield TextToSpeech ;
  #endif
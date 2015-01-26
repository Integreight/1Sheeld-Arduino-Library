/*

  Project:       1Sheeld Library 
  File:          TTSShield.h
                 
  Version:       1.2

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.9

*/

#ifndef TTSShield_h
#define TTSShield_h


#include "ShieldParent.h"

//Output Function ID
#define TTS_SAY 0x01


  class TTSShield: public ShieldParent
  {
  public:
    // Constructor
    TTSShield():ShieldParent(TTS_ID){};
    //Process
  	void say(const char *);
    void say(String );
  private:

  };

  //Extern Object
  extern TTSShield TextToSpeech ;
  #endif
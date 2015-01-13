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

//Output Function ID
#define TTS_SAY 0x01
#define TTS_SELECT_SHIELD 0xFE
#define TTS_UNSELECT_SHIELD 0xFD

//Input Function ID's
#define TTS_CHECK_SELECTED  0xFF

  class TTSShield
  {
  public:
    //Process
  	void say(const char *);
    void say(String );
    //Check selection
    void setOnSelected(void(*)());
    //Selection
    void select();
    void unselect();
  private:
    bool isCheckSelectedTriggered;

    void processData();
    void (*selectedCallBack)(void);

    friend class OneSheeldClass;
  };

  //Extern Object
  extern TTSShield TextToSpeech ;
  #endif
/*

  Project:       1Sheeld Library
  File:          VibrationShield.h

  Version:       1.6.1

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight

  Date:          2015.11

*/
#ifndef VibrationShield_h
#define VibrationShield_h

#include "ShieldParent.h"

#define NO_REPEAT 65535

//Output Function IDs
#define START_PATTERN_FN 0x01
#define START_DURATION_FN 0x02
#define STOP_VIBRATION_FN 0x03

class VibrationShield : public ShieldParent{
public:
  //Empty Constructor
  VibrationShield();
  //duration and repetitionDelay values range from 0 to 65534
  void start(int duration,int repetitionDelay = NO_REPEAT);
  //Pattern array has maximum length of 126
  //Each element in the pattern array range from 0 to 65534
  //repetitionDelay value range from 0 to 65534
  void start(byte patternLength,int pattern[],int repetitionDelay = NO_REPEAT);
  //Stop function stops repetitive vibrations
  void stop();
};
//External Object
extern VibrationShield Vibration;
#endif

/*

  Project:       1Sheeld Library
  File:          VibrationShield.h

  Version:       1.6.1

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Mostafa Mahmoud

  Email:         mostafa_mahmoud@protonmail.com

  Date:          2015.11

*/
#ifndef VibrationShield_h
#define VibrationShield_h

#include "ShieldParent.h"

#define VIBRATION_NO_REPEAT 65535

//Output Function IDs
#define VIBRATION_START_PATTERN 0x01
#define VIBRATION_START_DURATION 0x02
#define VIBRATION_STOP 0x03

class VibrationShield : public ShieldParent{
public:
  //Empty Constructor
  VibrationShield();
  //duration and repetitionDelay values range from 0 to 65534
  void start(int duration,int repetitionDelay = VIBRATION_NO_REPEAT);
  //Pattern array has maximum length of 127
  //Each element in the pattern array range from 0 to 65534
  //repetitionDelay value range from 0 to 65534
  void start(byte patternLength,int pattern[],int repetitionDelay = VIBRATION_NO_REPEAT);
  //Stop function stops vibrations
  void stop();
};
//External Object
extern VibrationShield Vibration;
#endif

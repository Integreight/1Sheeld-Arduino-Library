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

//Output Function IDs
#define VIBRATE_PATTERN_FN 0x01
#define VIBRATE_DURATION_FN 0x02
#define STOP_VIBRATION_FN 0x03

class VibrationShield : public ShieldParent{
public:
  //Empty Constructor
  VibrationShield();
  //Milliseconds and Repeat values range from 0 to 65534
  void vibrate(int milliseconds,int repeat = -1);
  //Repeat value range from 0 to 65534 and pattern array has maximum size of 126
  //Each element in the pattern array range from 0 to 65534
  //n is the pattern array size
  void vibrate(int n,int *pattern,int repeat = -1);
  //Stop function stops all repeatitive patterns
  void stop();
};
//External Object
extern VibrationShield Vibrator;
#endif

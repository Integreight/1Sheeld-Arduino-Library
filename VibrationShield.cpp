/*

  Project:       1Sheeld Library
  File:          VibrationShield.cpp

  Version:       1.6.1

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Mostafa Mahmoud

  Email:         mostafa_mahmoud@protonmail.com

  Date:          2015.11

*/
#define FROM_ONESHEELD_LIBRARY
#include "OneSheeld.h"
#include "VibrationShield.h"

//Constructor
VibrationShield::VibrationShield() : ShieldParent(VIBRATION_ID){
}

void VibrationShield::start(byte patternLength,int pattern[],int repetitionDelay){
  uint16_t *uint16Pattern = (uint16_t*) malloc(patternLength*sizeof(uint16_t));
  for(int i = 0; i < patternLength;i++){
    uint16Pattern[i] = (uint16_t) pattern[i];
  }
  OneSheeld.sendShieldFrame(VIBRATION_ID,0,VIBRATION_START_PATTERN,2,new FunctionArg(patternLength*sizeof(uint16_t),(byte*)uint16Pattern),new FunctionArg(sizeof(uint16_t),(byte*)&repetitionDelay));
  free(uint16Pattern);
}

void VibrationShield::start(int duration,int repetitionDelay){
  OneSheeld.sendShieldFrame(VIBRATION_ID,0,VIBRATION_START_DURATION,2,new FunctionArg(sizeof(uint16_t),(byte*)&duration),new FunctionArg(sizeof(uint16_t),(byte*)&repetitionDelay));
}

void VibrationShield::stop(){
  OneSheeld.sendShieldFrame(VIBRATION_ID,0,VIBRATION_STOP,0);
}

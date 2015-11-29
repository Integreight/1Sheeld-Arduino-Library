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
  OneSheeld.sendShieldFrame(VIBRATION_ID,0,START_PATTERN_FN,2,new FunctionArg(patternLength*sizeof(uint16_t),(byte*)uint16Pattern),new FunctionArg(sizeof(uint16_t),(byte*)&repetitionDelay));
  free(uint16Pattern);
}

void VibrationShield::start(int duration,int repetitionDelay){
  OneSheeld.sendShieldFrame(VIBRATION_ID,0,START_DURATION_FN,2,new FunctionArg(sizeof(uint16_t),(byte*)&duration),new FunctionArg(sizeof(uint16_t),(byte*)&repetitionDelay));
}

void VibrationShield::stop(){
  OneSheeld.sendShieldFrame(VIBRATION_ID,0,STOP_VIBRATION_FN,0);
}

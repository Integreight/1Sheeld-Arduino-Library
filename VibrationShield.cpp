#define FROM_ONESHEELD_LIBRARY
#include "OneSheeld.h"
#include "VibrationShield.h"

//Constructor
VibrationShield::VibrationShield() : ShieldParent(VIBRATION_ID){
}

void VibrationShield::vibrate(int n,int *pattern,int repeat){
  OneSheeld.sendShieldFrame(VIBRATION_ID,0,VIBRATE_PATTERN_FN,2,new FunctionArg(n*sizeof(int),(byte*)pattern),new FunctionArg(sizeof(int),(byte*)&repeat));
}

void VibrationShield::vibrate(int milliseconds,int repeat){
  OneSheeld.sendShieldFrame(VIBRATION_ID,0,VIBRATE_DURATION_FN,2,new FunctionArg(sizeof(int),(byte*)&milliseconds),new FunctionArg(sizeof(int),(byte*)&repeat));
}

void VibrationShield::stop(){
  OneSheeld.sendShieldFrame(VIBRATION_ID,0,STOP_VIBRATION_FN,0);
}

/*

  Project:       1Sheeld Library 
  File:          CameraShield.cpp
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/
#define FROM_ONESHEELD_LIBRARY  
#include "OneSheeld.h"
#include "CameraShield.h"


//Rear Capture   
void CameraShieldClass::rearCapture()
{
	OneSheeld.sendShieldFrame(CAMERA_ID,0,CAMERA_REAR_CAPTURE,0);
}
//Camera Flash   
void CameraShieldClass::setFlash(byte x)
{
	OneSheeld.sendShieldFrame(CAMERA_ID,0,CAMERA_SET_FLASH,1,new FunctionArg(1,&x));
}
//Front Capture 
void CameraShieldClass::frontCapture()
{
	OneSheeld.sendShieldFrame(CAMERA_ID,0,CAMERA_FRONT_CAPTURE,0);
}
//Quality Set 
void CameraShieldClass::setQuality(byte x)
{
	OneSheeld.sendShieldFrame(CAMERA_ID,0,CAMERA_SET_QUALITY,1,new FunctionArg(1,&x));
}


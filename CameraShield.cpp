/*

  Project:       1Sheeld Library 
  File:          CameraShield.cpp
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/

#include "OneSheeld.h"
#include "CameraShield.h"

//Rear Capture   
void CameraShieldClass::rearCapture()
{
	OneSheeld.sendPacket(CAMERA_ID,0,REAR_CAPTURE,0);
}
//Camera Flash   
void CameraShieldClass::setFlash(byte x)
{
	OneSheeld.sendPacket(CAMERA_ID,0,SET_FLASH,1,new FunctionArg(1,&x));
}
//Front Capture 
void CameraShieldClass::frontCapture()
{
	OneSheeld.sendPacket(CAMERA_ID,0,FRONT_CAPTURE,0);
}
//Quality Set 
void CameraShieldClass::setQuality(byte x)
{
	OneSheeld.sendPacket(CAMERA_ID,0,SET_QUALITY,1,new FunctionArg(1,&x));
}

//Instantiating Object
CameraShieldClass Camera;
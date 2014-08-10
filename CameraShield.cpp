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


CameraShieldClass::CameraShieldClass()
{
  motionFlag = 0;
  detectFrameSent = false;
}
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

void CameraShieldClass::recordVideo()
{
  OneSheeld.sendPacket(CAMERA_ID,0,VIDEO,0);
}

void CameraShieldClass::stopRecord()
{
  OneSheeld.sendPacket(CAMERA_ID,0,STOP_VIDEO,0);
}

bool CameraShieldClass::detectMotion()
{
  if(!detectFrameSent)
  {
    OneSheeld.sendPacket(CAMERA_ID,0,MOTION_DETECT,0);  
    detectFrameSent =true;
  }

  return motionFlag;
}

void CameraShieldClass::stopMotionDetection()
{
  detectFrameSent = false;
  OneSheeld.sendPacket(CAMERA_ID,0,STOP_MOTION,0);
}

void CameraShieldClass::processData()
{
  byte functionId = OneSheeld.getFunctionId();

  if(functionId == MOTION_DETECT)
  {
    motionFlag = OneSheeld.getArgumentData(0)[0];
  }
}
//Instantiating Object
CameraShieldClass Camera;
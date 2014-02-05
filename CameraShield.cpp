#include "OneSheeld.h"
#include "CameraShield.h"



CameraShieldClass::CameraShieldClass()
{}

void CameraShieldClass::capture()
{
	OneSheeld.sendPacket(CAMERA_ID,0,CAPTURE,0);
}

void CameraShieldClass::setFlash(byte x)
{
	OneSheeld.sendPacket(CAMERA_ID,0,SET_FLASH,1,new FunctionArg(1,&x));
}

CameraShieldClass CAM;
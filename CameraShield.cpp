#include "OneSheeld.h"
#include "CameraShield.h"


void CameraShieldClass::rearCapture()
{
	OneSheeld.sendPacket(CAMERA_ID,0,REAR_CAPTURE,0);
}

void CameraShieldClass::setFlash(byte x)
{
	OneSheeld.sendPacket(CAMERA_ID,0,SET_FLASH,1,new FunctionArg(1,&x));
}

void CameraShieldClass::frontCapture()
{
	OneSheeld.sendPacket(CAMERA_ID,0,FRONT_CAPTURE,0);
}

void CameraShieldClass::setResolution(byte x)
{
	OneSheeld.sendPacket(CAMERA_ID,0,SET_RESOLUTION,1,new FunctionArg(1,&x));
}
CameraShieldClass Camera;
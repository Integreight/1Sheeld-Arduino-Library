/*

  Project:       1Sheeld Library 
  File:          CameraShield.h
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/

#ifndef CameraShield_h
#define CameraShield_h

//Output Functions ID's
#define REAR_CAPTURE 	0x01
#define SET_FLASH 		0x02
#define FRONT_CAPTURE 	0x03
#define SET_QUALITY 	0x04
#define VIDEO			0x05
#define STOP_VIDEO		0x06
#define MOTION_DETECT	0x07
#define STOP_MOTION 	0x08
//Quality Control 
#define LOW_QUALITY 	0x01
#define MID_QUALITY 	0x02
#define HIG_QUALITY 	0x03
//Setting Flash 
#define OFF				0x00
#define ON    			0x01
#define AUTO  			0x02

class CameraShieldClass
{
public:
	CameraShieldClass();
	//Setters 
	void frontCapture();
	void rearCapture ();
	void setFlash(byte );
	void setQuality(byte);
	void recordVideo();
	void stopRecord();
	bool detectMotion();
	void stopMotionDetection();

private:
	bool detectFrameSent;
	bool motionFlag;
	void processData();
	friend class OneSheeldClass;
};

//Extern Object
extern CameraShieldClass Camera;
#endif 
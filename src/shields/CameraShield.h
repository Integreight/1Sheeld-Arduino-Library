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

#include "utility/ShieldParent.h"

//Output Functions ID's
#define CAMERA_REAR_CAPTURE 		0x01
#define CAMERA_SET_FLASH 			  0x02
#define CAMERA_FRONT_CAPTURE 		0x03
#define CAMERA_SET_QUALITY 			0x04

//Setting Flash (Literals)
#define OFF				  0x00
#define ON    			0x01
#define AUTO  			0x02
//Literals used by users
#define LOW_QUALITY  0x01
#define MID_QUALITY  0x02
#define HIGH_QUALITY  0x03
  
class CameraShieldClass : public ShieldParent
{
public:
  //Constructor
  CameraShieldClass():ShieldParent(CAMERA_ID){};
	//Setters 
	void frontCapture();
	void rearCapture ();
	void setFlash(byte );
	void setQuality(byte);

private:

};

//Extern Object
extern CameraShieldClass Camera;
#endif 
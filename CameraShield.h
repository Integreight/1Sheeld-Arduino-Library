#ifndef CameraShield_h
#define CameraShield_h


#define REAR_CAPTURE 	0x01
#define SET_FLASH 	0x02
#define FLASH_OFF	0x00
#define FLASH_ON    0x01
#define FLASH_AUTO  0x02
#define FRONT_CAPTURE 0x03
#define SET_QUALITY 0x04
#define LOW_QUALITY 0x01
#define MID_QUALITY 0x02
#define HIG_QUALITY 0x03

class CameraShieldClass
{
public:
	void frontCapture();
	void rearCapture ();
	void setFlash(byte );
	void setQuality(byte);

private:
	
};

extern CameraShieldClass Camera;
#endif 
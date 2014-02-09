#ifndef CameraShield_h
#define CameraShield_h


#define CAPTURE 	0xFF
#define SET_FLASH 	0x01

class CameraShieldClass
{
public:
	CameraShieldClass();
	void capture ();
	void setFlash(byte value);
private:
	
};

extern CameraShieldClass CAM;
#endif 
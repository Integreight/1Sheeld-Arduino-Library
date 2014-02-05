#ifndef CameraShield_h
#define CameraShield_h


#define CAPTURE 0x01
#define SET_FLASH 0x02

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
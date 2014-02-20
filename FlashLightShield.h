#ifndef FlashLightShield_h
#define FlashLightShield_h

#define SET_LOW 	0x00
#define SET_HIGH	0x01
#define SET_VALUE	0x01

class FlashLightShield
{
public:
	void setLow();
	void setHigh();
private:
	void setValue(byte );


};

extern FlashLightShield FlashLight;
#endif
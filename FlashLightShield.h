#ifndef FlashLightShield_h
#define FlashLightShield_h

#define SET_LOW 	0x00
#define SET_HIGH	0xFF
#define SET_VALUE	0x01

class FlashLightShield
{
public:
	FlashLightShield();
	void setLow();
	void setHigh();
	void setValue(byte );
private:


};

extern FlashLightShield Flash;
#endif
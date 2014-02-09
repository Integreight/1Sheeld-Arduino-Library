#ifndef LedShield_h
#define LedShield_h

#define SET_VALUE 0x01
#define SET_LOW	  0x00
#define SET_HIGH  0xFF

class LedShield
{
public:
	LedShield();
	void setLow();
	void setHigh();
	void setValue(byte );
private:

	

};

extern LedShield LED;
#endif
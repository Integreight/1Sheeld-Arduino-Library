#ifndef LedShield_h
#define LedShield_h

#define SET_VALUE 0x01
#define SET_LOW	  0x00
#define SET_HIGH  0x01

class LedShield
{
public:
	void setLow();
	void setHigh();
private:
	void setValue(byte );

	

};

extern LedShield LED;
#endif
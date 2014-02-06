#ifndef LedShield_h
#define LedShield_h

#define SET_VALUE 0x01


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
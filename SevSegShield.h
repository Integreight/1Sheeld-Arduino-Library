#ifndef SevSegShield_h
#define SevSegShield_h 



//#define BLINK_SEG 0x01
#define SET_NUMBER  0x01
#define SET_VALUE 0x02 

class SevSegShieldClass
{

public:
	SevSegShieldClass();
	//void blinkSeg ();
	void setNumber(byte x);
	void setValue(byte  );

private:
	

};

extern SevSegShieldClass SevSeg;
#endif

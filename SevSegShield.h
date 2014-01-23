#ifndef SevSegShield_h
#define SevSegShield_h 


#define OUT		0xff
#define BLINK_SEG 0x01
#define SET_SEG  0x05
#define SET_CHAR 0x06 

class SevSegShieldClass
{

public:
	SevSegShieldClass();
	void blinkSeg ();
	void setSeg(int x);
	void setCustomChar(char  );

private:
	char data ;
	char *dataptr;

};

extern SevSegShieldClass SevSeg;
#endif

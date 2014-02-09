#ifndef BuzzerShield_h
#define BuzzerShield_h


#define BUZZ_ON 	0xFF
#define BUZZ_OFF 	0x00
#define SET_VALUE 	0x01

class BuzzerShieldClass
{
public:
	BuzzerShieldClass();
	void buzzOn();
	void buzzOff();
	void setValue(byte x);

private:
	
};

extern BuzzerShieldClass Buzzer;
#endif
#ifndef BuzzerShield_h
#define BuzzerShield_h

#define BUZZ_ON 0x01
#define BUZZ_OFF 0x02
#define SET_VALUE 0x03

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
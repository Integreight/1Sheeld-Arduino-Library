#ifndef BuzzerShield_h
#define BuzzerShield_h


#define BUZZ_ON 	0x01
#define BUZZ_OFF 	0x00
#define SET_VALUE 	0x01

class BuzzerShieldClass
{
public:
	BuzzerShieldClass();
	void buzzOn();
	void buzzOff();
private:
	bool buzzing;
	void setValue(byte x);

};

extern BuzzerShieldClass Buzzer;
#endif
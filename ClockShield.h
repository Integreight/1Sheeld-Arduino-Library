#ifndef ClockShield_h
#define ClockShield_h

#define BEGIN_CLOCK 0x01
#define DATE_VALUE 0x01



class ClockShield
{
public:
	ClockShield();
	void begin();
	byte getSeconds();
	byte getHours();
	byte getMinutes();
	byte getDay();
	byte getMonth();
	short getYear();
private:
	void processData();
	byte seconds;
	byte hours;
	byte minutes;
	byte day;
	byte month;
	short year;
	bool isClockInit;
	friend class OneSheeldClass;

};

extern ClockShield Clock;
#endif
/*

  Project:       1Sheeld Library 
  File:          ClockShield.h
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/

#ifndef ClockShield_h
#define ClockShield_h

//Output Function ID
#define BEGIN_CLOCK 0x01
//Input Function ID
#define DATE_VALUE 0x01


class ClockShield
{
public:
	//Constructor
	ClockShield();
	//Begin Clock 
	void begin();
	//Getters 
	byte getSeconds();
	byte getHours();
	byte getMinutes();
	byte getDay();
	byte getMonth();
	short getYear();
private:
	//Reserve Variables
	byte seconds;
	byte hours;
	byte minutes;
	byte day;
	byte month;
	short year;
	//Boolean for Begin Function
	bool isClockInit;
	//Timeout Checkers
	unsigned long timeStart;
	unsigned long timeCheck;
	//Process Input Data 
	void processData();

	friend class OneSheeldClass;

};

//Extern Object
extern ClockShield Clock;
#endif
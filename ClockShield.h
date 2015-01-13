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
#define CLOCK_BEGIN 0x01
#define CLOCK_SELECT_SHIELD	0xFE
#define CLOCK_UNSELECT_SHIELD	0xFD
//Input Function ID
#define CLOCK_DATE_VALUE 0x01
#define CLOCK_CHECK_SELECTED	0xFF


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
	//Selection
	void select();
	void unselect();
	//Set on when selected
	void setOnSelected(void(*)(void));
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
	void (*selectedCallBack)(void);
	
	friend class OneSheeldClass;

};

//Extern Object
extern ClockShield Clock;
#endif
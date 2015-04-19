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

#include "ShieldParent.h"

//Output Function ID
#define CLOCK_BEGIN 0x01


//Input Function ID
#define CLOCK_DATE_VALUE 0x01

class ClockShield : public ShieldParent
{
public:
	//Constructor
	ClockShield();
	//Begin Clock 
	void queryDateAndTime();
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
	//Process Input Data 
	void processData();
};

//Extern Object
extern ClockShield Clock;
#endif
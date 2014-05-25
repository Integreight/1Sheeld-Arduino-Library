/*

  Project:       1Sheeld Library 
  File:          LEDShield.h
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/

#ifndef LedShield_h
#define LedShield_h

//Output Functions ID's
#define SET_VALUE 0x01
#define SET_LOW	  0x00
#define SET_HIGH  0x01

class LedShield
{
public:
	//Setters
	void setLow();
	void setHigh();
private:
	void setValue(byte );

};

//Extern Object
extern LedShield LED;
#endif
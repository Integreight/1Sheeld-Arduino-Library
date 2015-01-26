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

#include "ShieldParent.h"

//Output Functions ID's
#define LED_SET_HIGH  0x01

//Parameters
#define LED_SET_LOW   0x00
#define LED_SET_VALUE 0x01

class LedShield : public ShieldParent
{
public:
  //Constructor
  LedShield():ShieldParent(LED_ID){};
	//Setters
	void setLow();
	void setHigh();

private:
	void setValue(byte );
};

//Extern Object
extern LedShield LED;
#endif
/*

  Project:       1Sheeld Library 
  File:          PressureSensorShield.h
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/

#ifndef PressureSensorShield_h
#define PressureSensorShield_h

#include "ShieldParent.h"

//Input Function ID
#define PRESSURE_VALUE 0x01

class PressureSensorShield : public ShieldParent
{
public:
	//Constructor
	PressureSensorShield();
	//Getter
	int getValue();
	//setOnChange for Users Function
	void setOnValueChange(void (*)(unsigned  long));

private:
	//Reserve Variables
	int value;
	//Boolean For the setOnChange Function
	bool isCallBackAssigned;
	//Process Input Data 
	void processData();
	void (*changeCallBack)(unsigned long);
};

//Extern Object
extern PressureSensorShield PressureSensor;
#endif  
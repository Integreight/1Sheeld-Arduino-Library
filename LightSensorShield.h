/*

  Project:       1Sheeld Library 
  File:          LightSensorShield.h
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/

#ifndef LightSensorShield_h
#define LightSensorShield_h

#include "ShieldParent.h"

//Input Function ID 
#define LIGHT_VALUE 0x01

class LightSensorShield : public ShieldParent
{
public:
	//Constructor
	LightSensorShield();
	//Getter
	unsigned long getValue();
	//setOnChange for Users Function
	void setOnValueChange(void (*)(unsigned long));

private:
	//Reserve Variables
	unsigned long value;
	unsigned long data[3];
	//Boolean for the setOnChange Function
	bool isCallBackAssigned;
	//Process Input Data 
	void processData();
	void (*changeCallBack)(unsigned long);
};

//Extern Object
extern LightSensorShield LightSensor;
#endif  
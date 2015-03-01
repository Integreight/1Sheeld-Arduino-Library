/*

  Project:       1Sheeld Library 
  File:          TemperatureSensorShield.h
                 
  Version:       1.1

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/

#ifndef TemperatureSensorShield_h
#define TemperatureSensorShield_h

#include "ShieldParent.h"


//Input Function ID
#define TEMPERATURE_VALUE 0x01

class TemperatureSensorShield : public ShieldParent
{
public:
	//Constructor
	TemperatureSensorShield();
	//Getter
	char getValue();
	//setOnChange for Users Function
	void setOnValueChange(void (*)(char));
	//Helper Function 
	float getAsFahrenheit();

private:
	//Reserve Variable
	char value;
	//Boolean For the setOnChange Function
	bool isCallBackAssigned;
	//Process Input Data 
	void processData();
	void(*changeOnCallBack)(char);
};

//Extern Object
extern TemperatureSensorShield TemperatureSensor;
#endif
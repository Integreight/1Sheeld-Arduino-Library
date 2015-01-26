/*

  Project:       1Sheeld Library 
  File:          ProximitySensorShield.h
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/

#ifndef ProximitySensorShield_h
#define ProximitySensorShield_h

#include "ShieldParent.h"

//Input Function ID
#define PROXIMITY_VALUE 0x01

class ProximitySensorShield : public ShieldParent
{
public:
	//Constructor
	ProximitySensorShield();
	//Getter 
	byte getValue();
	//setOnChange for Users Function
	void setOnValueChange(void (*userFunction)(byte));

private:
	//Reserve Variables
	byte value;
	//Boolean For the setOnChange Function
	bool isCallBackAssigned;
	//Process Input Data 
	void processData();
	void (* changeCallBack)(byte);
};

//Extern Object
extern ProximitySensorShield ProximitySensor;

#endif
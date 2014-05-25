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

//Input Function ID
#define PRESSURE_VALUE 0x01

class PressureSensorShield
{
public:
	//Constructor
	PressureSensorShield();
	//Getter
	unsigned long getValue();
	//setOnChange for Users Function
	void setOnValueChange(void (*)(unsigned  long));
private:
	//Reserve Variables
	unsigned long value;
	unsigned long data[2];
	//Boolean For the setOnChange Function
	bool isCallBackAssigned;
	//Process Input Data 
	void processData();
	void (*changeCallBack)(unsigned long);
		
	friend class OneSheeldClass;


};

//Extern Object
extern PressureSensorShield PressureSensor;
#endif  
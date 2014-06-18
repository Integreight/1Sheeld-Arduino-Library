/*

  Project:       1Sheeld Library 
  File:          TemperatureSensorShield.h
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/

#ifndef TemperatureSensorShield_h
#define TemperatureSensorShield_h

//Input Function ID
#define TEMPERATURE_VALUE 0x01

class TemperatureSensorShield
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

	friend class OneSheeldClass;
};

//Extern Object
extern TemperatureSensorShield TemperatureSensor;
#endif
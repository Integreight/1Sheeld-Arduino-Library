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

//Output Function ID's
#define TEMPERATURE_SELECT_SHIELD 0xFE
#define TEMPERATURE_UNSELECT_SHIELD	0xFD

//Input Function ID
#define TEMPERATURE_VALUE 0x01
#define TEMPERATURE_CHECK_SELECTED	0xFF

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
	//Selection
	void select();
	void unselect();
	//Set On when selected
	void setOnSelected(void(*)(void));
private:
	//Reserve Variable
	char value;
	//Boolean For the setOnChange Function
	bool isCallBackAssigned;
	//Process Input Data 
	void processData();
	void(*changeOnCallBack)(char);
	void(*selectedCallBack)(void);

	friend class OneSheeldClass;
};

//Extern Object
extern TemperatureSensorShield TemperatureSensor;
#endif
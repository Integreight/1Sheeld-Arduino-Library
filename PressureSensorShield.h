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

//Output Function ID's
#define PRESSURE_SELECT_SHIELD	0x01
#define PRESSURE_UNSELECT_SHIELD	0x02
//Input Function ID
#define PRESSURE_VALUE 0x01
#define PRESSURE_CHECK_SELECTED	0x02

class PressureSensorShield
{
public:
	//Constructor
	PressureSensorShield();
	//Getter
	unsigned long getValue();
	//Selection
	void select();
	void unselect();
	//setOnChange for Users Function
	void setOnValueChange(void (*)(unsigned  long));
	void setOnSelected(void (*)(void));
private:
	//Reserve Variables
	unsigned long value;
	unsigned long data[2];
	//Boolean For the setOnChange Function
	bool isCallBackAssigned;
	//Process Input Data 
	void processData();
	void (*changeCallBack)(unsigned long);
	void (*selectedCallBack)(void);
		
	friend class OneSheeldClass;


};

//Extern Object
extern PressureSensorShield PressureSensor;
#endif  
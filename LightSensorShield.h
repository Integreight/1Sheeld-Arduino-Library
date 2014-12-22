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

//Output Function ID 
#define LIGHT_SELECT_SHIELD	0x01
#define LIGHT_UNSELECT_SHIELD	0x02

//Input Function ID 
#define LIGHT_VALUE 0x01
#define LIGHT_CHECK_SELECTED 0x02

class LightSensorShield
{
public:
	//Constructor
	LightSensorShield();
	//Getter
	unsigned long getValue();
	//Selection
	void select();
	void unselect();
	//setOnChange for Users Function
	void setOnValueChange(void (*)(unsigned long));
	void setOnSelected(void (*)(void));
private:
	//Reserve Variables
	unsigned long value;
	unsigned long data[3];
	//Boolean for the setOnChange Function
	bool isCallBackAssigned;
	//Process Input Data 
	void processData();
	void (*changeCallBack)(unsigned long);
	void (*selectedCallBack)(void);
	
	friend class OneSheeldClass;

};

//Extern Object
extern LightSensorShield LightSensor;
#endif  
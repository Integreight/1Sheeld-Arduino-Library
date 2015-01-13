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

//Output Function ID's
#define PROXIMITY_SELECT_SHIELD	0xFE
#define PROXIMITY_UNSELECT_SHIELD	0xFD
//Input Function ID
#define PROXIMITY_VALUE 0x01
#define PROXIMITY_CHECK_SELECTED 0xFF

class ProximitySensorShield
{
public:
	//Constructor
	ProximitySensorShield();
	//Getter 
	byte getValue();
	//Selection
	void select();
	void unselect();
	//setOnChange for Users Function
	void setOnValueChange(void (*userFunction)(byte));
	void setOnSelected(void(*)(void));
private:
	//Reserve Variables
	byte value;
	//Boolean For the setOnChange Function
	bool isCallBackAssigned;
	//Process Input Data 
	void processData();
	void (* changeCallBack)(byte);
	void (*selectedCallBack)(void);

	friend class OneSheeldClass;
};

//Extern Object
extern ProximitySensorShield ProximitySensor;

#endif
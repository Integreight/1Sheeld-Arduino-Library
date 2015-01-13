/*

  Project:       1Sheeld Library 
  File:          GravitySensorShield.h
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/

#ifndef GravitySensorShield_h
#define GravitySensorShield_h

//Output Function ID
#define GRAVITY_SELECT_SHIELD	0xFE
#define GRAVITY_UNSELECT_SHIELD	0xFD
//Input Function ID
#define GRAVITY_VALUE 0x01
#define GRAVITY_CHECK_SELECTED	0xFF


class GravitySensorShield
{
public:
	//Constructor
	GravitySensorShield();
	//Getter Functions
	float getX();
	float getY();
	float getZ();
	//Selection
	void select();
	void unselect();
	//setOnChange for Users Function
	void setOnValueChange(void (*)(float,float,float));
	void setOnSelected(void (*)(void));
private:
	//Reserve Variables
	float valueX ,valueY,valueZ;
	//Boolean for set On change Function
	bool isCallBackAssigned;
	//Process Input Data
	void processData();
	void (*changeCallBack)(float,float,float);
	void (*selectedCallBack)(void);
	friend class OneSheeldClass;


	
};

//Extern Object
extern GravitySensorShield GravitySensor;
#endif 
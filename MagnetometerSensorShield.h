/*

  Project:       1Sheeld Library 
  File:          MagnetometerSensorShield.h
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/

#ifndef MagnetometerSensorShield_h
#define MagnetometerSensorShield_h

//Output Function ID
#define MAGNETOMETER_SELECT_SHIELD	0xFE
#define MAGNETOMETER_UNSELECT_SHIELD	0xFD  
//Input Function ID 
#define MAGNETOMETER_VALUE 0x01
#define MAGNETOMETER_CHECK_SELECTED	0xFF  


class MagnetometerSensorShield
{
public:
	//Constructor 
	MagnetometerSensorShield();
	//Getters 
	float getX();
	float getY();
	float getZ();
	float getMagneticStrength();
	//Selection 
	void select();
	void unselect();
	//setOnChange for Users Function
	void setOnValueChange(void (*)(float ,float ,float));
	void setOnSelected(void(*)(void));
private:
	//Reserve Variables 
	float valueX ,valueY,valueZ;
	//Boolean for the setOnChange Function
	bool isCallBackAssigned;
	//Process Input Data 
	void processData();
	void (*changeCallBack)(float ,float ,float );
	void (*selectedCallBack)(void);
	friend class OneSheeldClass;

	
};

//Extern Object
extern MagnetometerSensorShield MagnetometerSensor;
#endif 
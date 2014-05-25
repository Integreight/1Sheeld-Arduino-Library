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

//Input Function ID 
#define MAGNETOMETER_VALUE 0x01


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
	//setOnChange for Users Function
	void setOnValueChange(void (*)(float ,float ,float));

private:
	//Reserve Variables 
	float valueX ,valueY,valueZ;
	//Boolean for the setOnChange Function
	bool isCallBackAssigned;
	//Process Input Data 
	void processData();
	void (*changeCallBack)(float ,float ,float );
	//Processing Float Numbers
	union 
	{
		byte data[4];
		float num;

	} getfloat;

	friend class OneSheeldClass;

	
};

//Extern Object
extern MagnetometerSensorShield MagnetometerSensor;
#endif 
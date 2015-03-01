/*

  Project:       1Sheeld Library 
  File:          AccelerometerSensorShield.h
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/

#ifndef AccelerometerSensorShield_h
#define AccelerometerSensorShield_h

#include "ShieldParent.h"

//Input Function ID 
#define ACCELEROMETER_VALUE 0x01




class AccelerometerSensorShield : public ShieldParent
{
public:
	//Constructor 
	AccelerometerSensorShield(); 
	//Getter Functions 
	float getX();
	float getY();
	float getZ();
	//setOnChange for Users Function
	void setOnValueChange(void (*)(float,float,float));
private:
	//Reserve Variables 
	float valueX,valueY,valueZ;
	//Boolean for setOnChange Function
	bool isCallBackAssigned;
	//Process Input Data  
	void processData();
	void (*changeCallBack)(float,float,float);	
};

//Extern Object
extern AccelerometerSensorShield AccelerometerSensor;
#endif
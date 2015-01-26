/*

  Project:       1Sheeld Library 
  File:          OrientationSensorShield.h
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/

#ifndef OrientationSensorShield_h
#define OrientationSensorShield_h

#include "ShieldParent.h"

//Input Function ID
#define ORIENTATION_VALUE 0x01

class OrientationSensorShield : public ShieldParent
{
public:
	//Constructor 
	OrientationSensorShield();
	//Getters
	float getX();
	float getY();
	float getZ();
	//setOnChange for Users Function
	void setOnValueChange(void (*)(float,float,float));

private:
	//Reserve Variables
	float valueX ,valueY,valueZ;
	//Boolean for the setOnChange Function
	bool isCallBackAssigned;
	//Process Input Data  
	void processData();
	void (*changeCallBack)(float,float,float);

	friend class OneSheeldClass;
};

//Extern Object
extern OrientationSensorShield OrientationSensor;
#endif 
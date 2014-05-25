/*

  Project:       1Sheeld Library 
  File:          GyroscopeSensorShield.h
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/

#ifndef GyroscopeSensorShield_h
#define GyroscopeSensorShield_h

//Input Function ID 
#define GYROSCOPE_VALUE 0x01

class GyroscopeSensorShield
{
public:
	//Constructor 
	GyroscopeSensorShield();
	//Getter Functions 
	float getX();
	float getY();
	float getZ();
	//setOnChange for Users Fucntion 
	void setOnValueChange(void (*)(float,float,float));
private:
	//Reserve Variables
	float valueX ,valueY,valueZ;
	//Boolean for the setOnChange Function
	bool isCallBackAssigned;
	//Process Input Data 
	void processData();
	void (*changeCallBack)(float,float,float);
	//Processing Float Numbers
	union 
	{
		byte data[4];
		float num;

	} getfloat;

	friend class OneSheeldClass;

	
};

//Extern Object
extern GyroscopeSensorShield GyroscopeSensor;
#endif 
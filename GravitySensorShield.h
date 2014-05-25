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

//Input Function ID
#define GRAVITY_VALUE 0x01


class GravitySensorShield
{
public:
	//Constructor
	GravitySensorShield();
	//Getter Functions
	float getX();
	float getY();
	float getZ();
	//setOnChange for Users Function
	void setOnValueChange(void (*)(float,float,float));
private:
	//Reserve Variables
	float valueX ,valueY,valueZ;
	//Boolean for set On change Function
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
extern GravitySensorShield GravitySensor;
#endif 
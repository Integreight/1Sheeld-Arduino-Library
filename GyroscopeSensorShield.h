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

//Output Function ID
#define GYROSCOPE_SELECT_SHIELD	0xFE
#define GYROSCOPE_UNSELECT_SHIELD	0xFD
//Input Function ID 
#define GYROSCOPE_VALUE 0x01
#define GYROSCOPE_CHECK_SELECTED 0xFF

class GyroscopeSensorShield
{
public:
	//Constructor 
	GyroscopeSensorShield();
	//Getter Functions 
	float getX();
	float getY();
	float getZ();
	//Selection
	void select();
	void unselect();
	//setOnChange for Users Fucntion 
	void setOnValueChange(void (*)(float,float,float));
	void setOnSelected(void (*)(void));
private:
	//Reserve Variables
	float valueX ,valueY,valueZ;
	//Boolean for the setOnChange Function
	bool isCallBackAssigned;
	//Process Input Data 
	void processData();
	void (*changeCallBack)(float,float,float);
	void (*selectedCallBack)(void);

	friend class OneSheeldClass;

	
};

//Extern Object
extern GyroscopeSensorShield GyroscopeSensor;
#endif 
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

//Output Function ID
#define ACCELEROMETER_SELECT_SHIELD	0x01
#define ACCELEROMETER_UNSELECT_SHIELD	0x02
//Input Function ID 
#define ACCELEROMETER_VALUE 0x01
#define ACCELEROMETER_CHECK_SELECTED	0x02



class AccelerometerSensorShield
{
friend class OneSheeldClass;
public:
	//Constructor 
	AccelerometerSensorShield(); 
	//Getter Functions 
	float getX();
	float getY();
	float getZ();
	//setOnChange for Users Function
	void setOnValueChange(void (*)(float,float,float));
	//Selection
	void select();
	void unselect();
	//Set on when selected
	void setOnSelected(void(*)(void));
private:
	//Reserve Variables 
	float valueX,valueY,valueZ;
	//Boolean for setOnChange Function
	bool isCallBackAssigned;
	//Process Input Data  
	void processData();
	void (*changeCallBack)(float,float,float);	
	void (*selectedCallBack)(void);
};

//Extern Object
extern AccelerometerSensorShield AccelerometerSensor;
#endif
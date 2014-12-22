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

//Output Function ID
#define OREINTATION_SELECT_SHIELD	0x01
#define OREINTATION_UNSELECT_SHIELD	0x02
//Input Function ID
#define ORIENTATION_VALUE 0x01
#define ORIENTATION_CHECK_SELECTED	0x02


class OrientationSensorShield
{
public:
	//Constructor 
	OrientationSensorShield();
	//Getters
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
	//Boolean for the setOnChange Function
	bool isCallBackAssigned;
	//Process Input Data  
	void processData();
	void (*changeCallBack)(float,float,float);
	void (*selectedCallBack)(void);
	friend class OneSheeldClass;

	
};

//Extern Object
extern OrientationSensorShield OrientationSensor;
#endif 
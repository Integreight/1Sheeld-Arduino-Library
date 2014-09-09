/*

  Project:       1Sheeld Library 
  File:          MagnetometerSensorShield.cpp
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/

#include "OneSheeld.h"
#include "MagnetometerSensorShield.h"
#include <math.h>


//Class Constructor
MagnetometerSensorShield::MagnetometerSensorShield()
{
	valueX=0;
	valueY=0;
	valueZ=0;
	isCallBackAssigned=false;
}
//X-Axis getter function
float MagnetometerSensorShield::getX()
{
	return valueX;
}
//Y-Axis getter function
float MagnetometerSensorShield::getY()
{
	return valueY;
}
//Z-Axis getter function
float MagnetometerSensorShield::getZ()
{
	return valueZ;
}
//MagnetometerSensor Data processing 	
void MagnetometerSensorShield::processData()
{
	byte shieldId=OneSheeld.getShieldId();
	//Check Function-ID
	byte functionId=OneSheeld.getFunctionId();
	
		if(functionId==MAGNETOMETER_VALUE)
		{
			//Process X-Axis Value
			valueX=OneSheeld.convertBytesToFloat(OneSheeld.getArgumentData(0));
			//Process Y-Axis Value
			valueY=OneSheeld.convertBytesToFloat(OneSheeld.getArgumentData(1));
			//Process Z-Axis Value
			valueZ=OneSheeld.convertBytesToFloat(OneSheeld.getArgumentData(2));
			
			//User Function Invoked
			if(isCallBackAssigned)
			{
				(*changeCallBack)(valueX,valueY,valueZ);
			}
		}
}

//Users Function Setter 
void MagnetometerSensorShield::setOnValueChange(void (*userFunction)(float valueX, float valueY ,float valueZ))
{
	changeCallBack=userFunction;
	isCallBackAssigned=true;
}
//Helper
float MagnetometerSensorShield::getMagneticStrength()
{
	return sqrt((valueX*valueX)+(valueY*valueY)+(valueZ*valueZ));
}

//Instatntiating Object
MagnetometerSensorShield MagnetometerSensor;
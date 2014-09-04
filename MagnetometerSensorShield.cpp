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
	
	if(shieldId==MAGNETOMETER_ID)
	{
		if(functionId==MAGNETOMETER_VALUE)
		{
			valueX=0;
			valueY=0;
			valueZ=0;
			
			OneSheeld.SensorsFloat.sensorsData[0]=OneSheeld.getArgumentData(0)[0];		
			OneSheeld.SensorsFloat.sensorsData[1]=OneSheeld.getArgumentData(0)[1];
			OneSheeld.SensorsFloat.sensorsData[2]=OneSheeld.getArgumentData(0)[2];
			OneSheeld.SensorsFloat.sensorsData[3]=OneSheeld.getArgumentData(0)[3];
			valueX=OneSheeld.SensorsFloat.number;

		    //Process Y-Axis Value
		    OneSheeld.SensorsFloat.sensorsData[0]=OneSheeld.getArgumentData(1)[0];		
			OneSheeld.SensorsFloat.sensorsData[1]=OneSheeld.getArgumentData(1)[1];
			OneSheeld.SensorsFloat.sensorsData[2]=OneSheeld.getArgumentData(1)[2];
			OneSheeld.SensorsFloat.sensorsData[3]=OneSheeld.getArgumentData(1)[3];
			valueY=OneSheeld.SensorsFloat.number;

		    //Process Z-Axis Value
		    OneSheeld.SensorsFloat.sensorsData[0]=OneSheeld.getArgumentData(2)[0];		 
			OneSheeld.SensorsFloat.sensorsData[1]=OneSheeld.getArgumentData(2)[1];
			OneSheeld.SensorsFloat.sensorsData[2]=OneSheeld.getArgumentData(2)[2];
			OneSheeld.SensorsFloat.sensorsData[3]=OneSheeld.getArgumentData(2)[3];
			valueZ=OneSheeld.SensorsFloat.number;
			//User Function Invoked
			if(isCallBackAssigned)
			{
				(*changeCallBack)(valueX,valueY,valueZ);
			}
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
/*

  Project:       1Sheeld Library 
  File:          GyroscopeSensorShield.cpp
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/

#include "OneSheeld.h"
#include "GyroscopeSensorShield.h"

//Class Constructor 
GyroscopeSensorShield::GyroscopeSensorShield()
{
	valueX=0;
	valueY=0;
	valueZ=0;
	isCallBackAssigned=false;
}

//X-Axis getter function
float GyroscopeSensorShield::getX()
{
	return valueX;
}
//Y-Axis getter function
float GyroscopeSensorShield::getY()
{
	return valueY;
}
//Z-Axis getter function
float GyroscopeSensorShield::getZ()
{
	return valueZ;
}

void GyroscopeSensorShield::select()
{
	OneSheeld.sendPacket(GYROSCOPE_ID,0,GYROSCOPE_SELECT_SHIELD,0);
}

void GyroscopeSensorShield::unselect()
{
	OneSheeld.sendPacket(GYROSCOPE_ID,0,GYROSCOPE_UNSELECT_SHIELD,0);
}
//GyroscopeSensor Input Data processing 	
void GyroscopeSensorShield::processData()
{
	//Check Function-ID
	byte functionId=OneSheeld.getFunctionId();
	
		if(functionId==GYROSCOPE_VALUE)
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
		else if(functionId == GYROSCOPE_CHECK_SELECTED)
		{
			(*selectedCallBack)();
		}
}

//Users Function Setter 
void GyroscopeSensorShield::setOnValueChange(void (*userFunction)(float valueX, float valueY ,float valueZ))
{
	changeCallBack=userFunction;
	isCallBackAssigned=true;
}

void GyroscopeSensorShield::setOnSelected(void (*userFunction)(void))
{
	selectedCallBack=userFunction;
}
//Instatntiating Object
GyroscopeSensorShield GyroscopeSensor ;
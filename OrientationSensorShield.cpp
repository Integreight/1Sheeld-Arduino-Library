/*

  Project:       1Sheeld Library 
  File:          OrientationSensorShield.cpp
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/

#include "OneSheeld.h"
#include "OrientationSensorShield.h"


//Class Constructor
OrientationSensorShield::OrientationSensorShield()
{
	valueX=0;
	valueY=0;
	valueZ=0;
	isCallBackAssigned=false;
}

//X-Axis getter function
float OrientationSensorShield::getX()
{
	return valueX;
}
//Y-Axis getter function
float OrientationSensorShield::getY()
{
	return valueY;
}
//Z-Axis getter function
float OrientationSensorShield::getZ()
{
	return valueZ;
}

void OrientationSensorShield::select()
{
	OneSheeld.sendPacket(ORIENTATION_ID,0,OREINTATION_SELECT_SHIELD,0);
}

void OrientationSensorShield::unselect()
{
	OneSheeld.sendPacket(ORIENTATION_ID,0,OREINTATION_UNSELECT_SHIELD,0);
}
//AccelerometerSensor Data processing 
void OrientationSensorShield::processData()
{
	//Check Function-ID
	byte functionId=OneSheeld.getFunctionId();
	
		if(functionId==ORIENTATION_VALUE)
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
		else if(functionId == ORIENTATION_CHECK_SELECTED)
		{
			(*selectedCallBack)();
		}
}

//Users Function Setter
void OrientationSensorShield::setOnValueChange(void (*userFunction)(float valueX,float valueY ,float valueZ))
{
	changeCallBack=userFunction;
	isCallBackAssigned=true;
}

void OrientationSensorShield::setOnSelected(void (*userFunction)(void))
{
	selectedCallBack=userFunction;
}
//Instatntiating Object
OrientationSensorShield OrientationSensor;
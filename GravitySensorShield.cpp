/*

  Project:       1Sheeld Library 
  File:          GravitySensorShield.cpp
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/
#include "OneSheeld.h"
#include "GravitySensorShield.h"


//Class Constructor 
GravitySensorShield::GravitySensorShield() : ShieldParent(GRAVITY_ID)
{
	valueX=0;
	valueY=0;
	valueZ=0;
	isCallBackAssigned=false;

}

//X-Axis getter function
float GravitySensorShield::getX()
{
	return valueX;
}
//Y-Axis getter function
float GravitySensorShield::getY()
{
	return valueY;
}
//Z-Axis getter function
float GravitySensorShield::getZ()
{
	return valueZ;
}

//Gravity Input Data Processing 
void GravitySensorShield::processData()
{
	//Check Function-ID
	byte functionId=OneSheeld.getFunctionId();
	
		if(functionId==GRAVITY_VALUE)
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

//User Function Setter 
void GravitySensorShield::setOnValueChange(void (*userFunction)(float valueX,float valueY,float valueZ))
{
	changeCallBack=userFunction;
	isCallBackAssigned=true;
}

#ifdef GRAVITY_SHIELD
//Instantiating Object
GravitySensorShield GravitySensor ;
#endif
/*

  Project:       1Sheeld Library 
  File:          GPSShield.cpp
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/
#define FROM_ONESHEELD_LIBRARY
#include "OneSheeld.h"
#include "GPSShield.h"

//Class Constructor 
GPSShieldClass::GPSShieldClass () : ShieldParent(GPS_ID)
{
	LatValue=0;
	LonValue=0;
	isInit=false;
	isCallBackAssigned=false;
}

//GPS Input Data Processing 
void GPSShieldClass::processData ()
{
	//Checking Function-ID
	byte functionId=getOneSheeldInstance().getFunctionId();
	if(functionId==GPS_VALUE)
	{

		LatValue=getOneSheeldInstance().convertBytesToFloat(getOneSheeldInstance().getArgumentData(0));

		LonValue=getOneSheeldInstance().convertBytesToFloat(getOneSheeldInstance().getArgumentData(1));

		isInit=true;  									//setting a flag 
	}
	//Users Function Invoked
	if (isCallBackAssigned && !isInACallback())
	{
		enteringACallback();
		(*changeCallBack)(LatValue,LonValue);
		exitingACallback();
	}
}

//Getter 
float GPSShieldClass::getLatitude()
{
	return LatValue;
}

//Getter
float GPSShieldClass::getLongitude()
{
	return LonValue;
}

//Helper 
bool GPSShieldClass::isInRange(float usersValue1 , float usersValue2,float range)
{
	if(!isInit)return false;
	float x= getDistance(usersValue1 , usersValue2);
	if( x >=0 && x < range)
	{
			return true;		
	}
	else
	{
		return false;
	}

}
//Helper
float GPSShieldClass::getDistance(float x , float y)			//x and y is the lattitude and the longitude inserted by the user 
{
	if(!isInit)return 0;
	float dLat = radian(x-LatValue);			//difference betwwen the two lattitude point  
	float dLon = radian(y-LonValue);			//difference betwwen the two longitude point  

	float chordProcess    = sin(dLat/2)*sin(dLat/2)+sin(dLon/2)*sin(dLon/2)*cos(radian(LatValue))*cos(radian(x));
	float angularDistance = 2*atan2(sqrt(chordProcess),sqrt(1-chordProcess));
	float actualDsitance  = (RADIUS_OF_EARTH*angularDistance)*1000;			//getting the actuall distance in meters

	return actualDsitance;											
}

//Helper
float GPSShieldClass::radian(float value)
{
	float radianValue = value*(PI/180);
	return radianValue;
}

//User Function Setter
void GPSShieldClass::setOnValueChange(void (*userFunction)(float lattitude ,float longitude))
{
	changeCallBack=userFunction;
	isCallBackAssigned=true;
}


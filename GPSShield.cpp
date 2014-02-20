//GPS shield getting the langittude and the latittude from the  Android 
#include "OneSheeld.h"
#include "GPSShield.h"
#include "HardwareSerial.h"

//initializing the array of the Long and the Lati 
GPSShieldClass::GPSShieldClass ()
{
	LatValue=0xFF;
	LonValue=0xFF;
}

//reading the packet and assigning the values to the long and the latit  
void GPSShieldClass::Proc ()
{
	getfloat.data[0]=OneSheeld.getArgumentData(0)[0];
	getfloat.data[1]=OneSheeld.getArgumentData(0)[1];
	getfloat.data[2]=OneSheeld.getArgumentData(0)[2];
	getfloat.data[3]=OneSheeld.getArgumentData(0)[3];
	LatValue=getfloat.num;

	getfloat.data[0]=OneSheeld.getArgumentData(1)[0];
	getfloat.data[1]=OneSheeld.getArgumentData(1)[1];
	getfloat.data[2]=OneSheeld.getArgumentData(1)[2];
	getfloat.data[3]=OneSheeld.getArgumentData(1)[3];
	LonValue=getfloat.num;

}

float GPSShieldClass::getLattitude()
{
	return LatValue;
}


float GPSShieldClass::getLongitude()
{
	return LonValue;
}

bool GPSShieldClass::isInRange(float usersValue1 , float usersValue2,float range)
{
	if(getDistance(usersValue1 , usersValue2)>=0 && getDistance(usersValue1 , usersValue2)<range)
	{
			return true;		
	}
	else
	{
		return false;
	}

}

float GPSShieldClass::getDistance(float x , float y)			//x and y is the lattitude and the longitude inserted by the user 
{

	float dLat = x-LatValue;			//difference betwwen the two lattitude point  
	float dLon = y-LonValue;			//difference betwwen the two longitude point  

	float chordProcess    = sin(dLat/2)*sin(dLat/2)+sin(dLon/2)*sin(dLon/2)*cos(LatValue)*cos(x);
	float angularDistance = 2*atan2(sqrt(chordProcess),sqrt(1-chordProcess));
	float actualDsitance  = (R*angularDistance)*1000;			//getting the actuall distance in meters

	return actualDsitance;											
}

GPSShieldClass  GPS ;
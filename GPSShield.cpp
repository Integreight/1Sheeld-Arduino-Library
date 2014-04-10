//GPS shield getting the langittude and the latittude from the  Android 
#include "OneSheeld.h"
#include "GPSShield.h"

//initializing the array of the Long and the Lati 
GPSShieldClass::GPSShieldClass ()
{
	LatValue=0;
	LonValue=0;
	isInit=false;
	isCallBackAssigned=false;
}

//reading the packet and assigning the values to the long and the latit  
void GPSShieldClass::processData ()
{
	byte functionId=OneSheeld.getFunctionId();
	if(functionId==GPS_VALUE)
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

		isInit=true;  									//setting a flag 
	}
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

float GPSShieldClass::getDistance(float x , float y)			//x and y is the lattitude and the longitude inserted by the user 
{
	if(!isInit)return 0;
	float dLat = radian(x-LatValue);			//difference betwwen the two lattitude point  
	float dLon = radian(y-LonValue);			//difference betwwen the two longitude point  

	float chordProcess    = sin(dLat/2)*sin(dLat/2)+sin(dLon/2)*sin(dLon/2)*cos(radian(LatValue))*cos(radian(x));
	float angularDistance = 2*atan2(sqrt(chordProcess),sqrt(1-chordProcess));
	float actualDsitance  = (RADUIS_OF_EARTH*angularDistance)*1000;			//getting the actuall distance in meters

	return actualDsitance;											
}
float GPSShieldClass::radian(float value)
{
	float radianValue = value*(PI/180);
	return radianValue;
}

void GPSShieldClass::setOnChange(void (*userFunction)())
{
	changeCallBack=userFunction;
	isCallBackAssigned=true;
}
GPSShieldClass  GPS ;
//GPS shield getting the langittude and the latittude from the  Android 
#include "OneSheeld.h"
#include "GPSShield.h"
#include "HardwareSerial.h"

//initializing the array of the Long and the Lati 
GPSShieldClass::GPSShieldClass ()
{
	for (int i=0;i<4;i++)
	{
		Long[i]=0x00;
		Latt[i]=0x00;
	} 
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

//Confirmation for the longitude and the latitude used by the programmer
bool GPSShieldClass::isLongitude()
{
	if (Long[3]=='W'||Long[3]=='E')
		return true ;
	else 
		return false;
}

bool GPSShieldClass::isLatitude()
{
	if (Latt[3]=='N'||Latt[3]=='S')
		return true;
	else 
		return false;
}

bool GPSShieldClass::isInRange(double usersValue1, double usersValue2 ,double range)
{
	double dLat=usersValue1-LatValue;
	double dLon=usersValue2-LonValue;

	double chordProcess    = sin(dLat/2)*sin(dLat/2)+sin(dLon/2)*sin(dLon/2)*cos(LatValue)*cos(usersValue1);
	double angularDistance = 2*atan2(sqrt(chordProcess),sqrt(1-chordProcess));
	double actualDsitance  = (R*angularDistance)*1000;											//getting the actuall distance in meters

	if(actualDsitance>=0 && actualDsitance<range)
	{
			return true;		
	}
	else
	{
		return false;
	}

}

GPSShieldClass  GPS ;
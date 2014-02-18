//GPS shield getting the langittude and the latittude from the  Android 
#include "OneSheeld.h"
#include "GPSShield.h"
#include "HardwareSerial.h"


//constructors to get the longitude and the latitude without the use of arrays 
GPSCoordinate::GPSCoordinate(char deg,char min ,char sec,char side)
{
		degree=deg;
		minutes=min;
		seconds=sec;
		type=side;
}
char GPSCoordinate::getDegree()
{
	return degree ;
}
char GPSCoordinate::getMinutes()
{
	return minutes;
}
char GPSCoordinate::getSeconds()
{
	return seconds;
}
char GPSCoordinate::getCharacter()
{
	return type;
}


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

	for (int i=0;i<4;i++)
	{
		
		Long[i]=OneSheeld.getArgumentData(0)[i];


	}
		
	for (int i=0;i<4;i++)
	{
		Latt[i]=OneSheeld.getArgumentData(1)[i];
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
//get the Longitude 
GPSCoordinate GPSShieldClass::getLon()
{

	return GPSCoordinate(Long[0],Long[1],Long[2],Long[3]);

}

//get the latitude 
GPSCoordinate GPSShieldClass::getLat()
{

	 return GPSCoordinate(Latt[0],Latt[1],Latt[2],Latt[3]);
}


//Confirmation for the longitude and the latitude used by the programmer
bool GPSShieldClass::isLongitude()
{
	if (Long[3]=='W'||Long[3]=='E')
		return true ;
	else 
		false;
}

bool GPSShieldClass::isLatitude()
{
	if (Latt[3]=='N'||Latt[3]=='S')
		return true;
	else 
		false;
}
GPSShieldClass  GPS ;
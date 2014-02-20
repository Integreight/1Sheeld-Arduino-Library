#include "OneSheeld.h"
#include "AccelerometerSensorShield.h"




AccelerometerSensorShield::AccelerometerSensorShield()
{
	valueX=0;
	valueY=0;
	valueZ=0;
}


float AccelerometerSensorShield::getX()
{
	return valueX;
}

float AccelerometerSensorShield::getY()
{
	return valueY;
}

float AccelerometerSensorShield::getZ()
{
	return valueZ;
}

void AccelerometerSensorShield::processData()
{
	//getting the float of first 4bytes
	getfloat.data[0]=OneSheeld.getArgumentData(0)[0];
	getfloat.data[1]=OneSheeld.getArgumentData(0)[1];
	getfloat.data[2]=OneSheeld.getArgumentData(0)[2];
	getfloat.data[3]=OneSheeld.getArgumentData(0)[3];
	valueX=getfloat.num;
	//Serial.println(valueX,10);
    //getting the float of second 4bytes
    getfloat.data[0]=OneSheeld.getArgumentData(1)[0];
	getfloat.data[1]=OneSheeld.getArgumentData(1)[1];
	getfloat.data[2]=OneSheeld.getArgumentData(1)[2];
	getfloat.data[3]=OneSheeld.getArgumentData(1)[3];
	valueY=getfloat.num;
    //getting the float of third 4bytes
    getfloat.data[0]=OneSheeld.getArgumentData(2)[0];
	getfloat.data[1]=OneSheeld.getArgumentData(2)[1];
	getfloat.data[2]=OneSheeld.getArgumentData(2)[2];
	getfloat.data[3]=OneSheeld.getArgumentData(2)[3];
	valueZ=getfloat.num;
}

AccelerometerSensorShield Accelerometer;
#include "OneSheeld.h"
#include "MagnetometerSensorShield.h"





MagnetometerSensorShield::MagnetometerSensorShield()
{
	valueX=0;
	valueY=0;
	valueZ=0;
	isCallBackAssigned=false;
}


float MagnetometerSensorShield::getX()
{
	return valueX;
}

float MagnetometerSensorShield::getY()
{
	return valueY;
}

float MagnetometerSensorShield::getZ()
{
	return valueZ;
}

void MagnetometerSensorShield::processData()
{
	byte functionId= OneSheeld.getFunctionId();
	if(functionId==MAGNETOMETER_VALUE)
	{
		valueX=0;
		valueY=0;
		valueZ=0;
		//getting the float of first 4bytes
		getfloat.data[0]=OneSheeld.getArgumentData(0)[0];
		getfloat.data[1]=OneSheeld.getArgumentData(0)[1];
		getfloat.data[2]=OneSheeld.getArgumentData(0)[2];
		getfloat.data[3]=OneSheeld.getArgumentData(0)[3];
		valueX=getfloat.num;
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

		if(isCallBackAssigned)
		{
			(*changeCallBack)();
		}
	}
}

void MagnetometerSensorShield::setOnChange(void (*userFunction)())
{
	changeCallBack=userFunction;
	isCallBackAssigned=true;
}

float MagnetometerSensorShield::magneticStrength()
{
	return sqrt((valueX*valueX)+(valueY*valueY)+(valueZ*valueZ));
}


MagnetometerSensorShield MagnetometerSensor;
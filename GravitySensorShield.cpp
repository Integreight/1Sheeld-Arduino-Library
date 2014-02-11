#include "OneSheeld.h"
#include "GravitySensorShield.h"
#include "HardwareSerial.h"




GravitySensorShield::GravitySensorShield()
{
	valueX=0;
	valueY=0;
	valueZ=0;
	x=0;
	y=0;
	
}


float GravitySensorShield::getX_Axis()
{
	return valueX;
}

float GravitySensorShield::getY_Axis()
{
	return valueY;
}

float GravitySensorShield::getZ_Axis()
{
	return valueZ;
}

void GravitySensorShield::processData()
{
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
    

/*
	if(x==4){
      if(y==1)
      {
        valueY=getfloat.num;
        Serial.println(valueY,10);
      }
      if(y==2)
      {
        valueZ=getfloat.num;
        Serial.println(valueZ,10);
      }
      valueX=getfloat.num;
    Serial.println(valueX,10);
    y++;
    x=0;
    }*/ 
}


GravitySensorShield Gravity ;
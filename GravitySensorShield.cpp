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
	Serial.write(OneSheeld.getArgumentData(0)[0]);
	for (int i=0 ;i<4;i++)
	{getfloat.data[x++]=OneSheeld.getArgumentData(y)[x];}
	Serial.write(getfloat.data[0]);
	Serial.write(getfloat.data[1]);
	Serial.write(getfloat.data[2]);
	Serial.write(getfloat.data[3]);
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
    } 
}


GravitySensorShield Gravity ;
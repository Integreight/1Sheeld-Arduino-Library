/*
Example illustrates the Orientation shield using the Orientation Sensor of the Smartphone
to allign a portrait on the wall and when oriented properly the phone buzzes
i.e:
my phone X-Axis 0--->360 / Y-Axis -180--->180 / Z-Axis -90--->90 
so check out your phone axis
*/

/*Include OneSheeld Library*/
#include <OneSheeld.h>


void setup () 
{
  /*Start Communication*/
  OneSheeld.begin();
}

void loop () 
{
  /*Always get the Y-Axis and Z-Axis coordinations and if they equal or near zero buzzOn*/
  if (OrientationSensor.getY()>-1&&OrientationSensor.getY()<=0)
  {
    /*Check the Z-Axis if it's near the range from -1 to 0*/
    if(OrientationSensor.getZ() >-1 && OrientationSensor.getZ() <1)
    { 
      Buzzer.buzzOn();
    }
    /*Buzz off when the second condition of the Z-Axis is not right*/
    else
    {
      Buzzer.buzzOff();
    }
  }
  /*Buzz off when the first condition of the Y-Axis is not right*/
  else
  {
    Buzzer.buzzOff();
  }
  
  
}

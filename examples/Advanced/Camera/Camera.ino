/*
Example illustrates Sensing the Light and if its beyond a certain
Limit take a Picture
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
  /*Always get the value of the Light Sensor*/
  if(LightSensor.getValue()<100 && LightSensor.getValue()>0)
  {
    /*Set the Flash of the Camera to be On while capturing*/
    Camera.setFlash(ON);
    /*Capture a picture*/
    Camera.rearCapture();
    /*Adding a time delay for 5 minutes*/
    delay(50000);
  }
  
}

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
  /*Set the Flash of the Camera to be On while capturing*/
  Camera.setFlash(FLASH_ON);
}


void loop ()
{
  /*Always get the value of the Light Sensor*/
  if(LightSensor.getValue()<100 && LightSensor.getValue()>0)
  {
    /*Capture a picture*/
    Camera.rearCapture();
    /*Adding a time delay  to handle the Capturing against the speed of loop*/
    delay(1000);
  }
  
}

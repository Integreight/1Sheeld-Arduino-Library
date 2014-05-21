/*
Example illustrates the Proximity Sensor of the Smartphone if any object is near
it Capture a picture and send me a message!! 
*/

/*Include OnSheeld Library*/
#include <OneSheeld.h>


void setup ()
{
  /*Start Communication*/
  OneSheeld.begin();
  /*Set the Flash of the Camera*/
  Camera.setFlash(ON);
  /*Invoke the Function if a change happend*/
  ProximitySensor.setOnChange(& proximity);
}


void loop ()
{}

/*Function invoked once proximity value changed*/
void proximity (byte value)
{
  /*Always checking the proximity sensor if something goes near, capture and send me SMS*/
  if (ProximitySensor.getValue()==0)
  {
    Camera.rearCapture();
    SMS.send("+0201286077028","Something or Someone Passed near the place");
  }
}
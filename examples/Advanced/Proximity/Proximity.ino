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
}


void loop ()
{
  /*Always checking the proximity sensor if something goes near, capture and send me SMS*/
  if (ProximitySensor.getValue()==0)
  {
    Camera.rearCapture();
    SMS.send("+0201286077028","Something or Someone Passed near the place");
  }
}

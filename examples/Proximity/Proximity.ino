/*
Example illustrates the Proximity Sensor of the Smart Phone if any object is near
it Capture a picture and send me a message!! 
*/

//including the OnSheeld Library 
#include <OneSheeld.h>


void setup ()
{
  //Starting the UART communication on baudrate 57600
  OneSheeld.begin();
}


void loop ()
{
  //always checking the proximity sensor if something got near capture and send me SMS  
  if (ProximitySensor.getValue()==0)
  {
    Camera.capture();
    SMS.send("+0201286077028","Something or Someone Passed near the place");
  }
}

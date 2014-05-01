/*
Example Illustrates Buzzer buzze On each and every time you get near the 
Smart phone using the Proximity Sensor
*/

/*Including the OneSheeld Library*/
#include <OneSheeld.h>

void setup () 
{
  /*Start UART communication on baudrate 57600*/
  OneSheeld.begin();
}


void loop ()
{
  /*Check out if something is near the Smart Phone buzz immediately*/
  if (ProximitySensor.getValue()==0)
  {
    /*Always buzz On when the something is near the Phone*/
    Buzzer.buzzOn();
  }
  else 
  {
    /*Buzz off when nothing is near*/
    Buzzer.buzzOff();
  }
}

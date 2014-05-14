/*
Example Illustrates Buzzer buzz On each and every time you get near your 
Smartphone using Proximity Sensor
*/

/*Including the OneSheeld Library*/
#include <OneSheeld.h>

void setup () 
{
  /*Start Communication*/
  OneSheeld.begin();
}


void loop ()
{
  /*Check out if something is near the Phone, buzz immediately*/
  if (ProximitySensor.getValue()==0)
  {
    /*Always buzz On when the something is near the Phone*/
    Buzzer.buzzOn();
  }
  else 
  {
    /*Buzz off*/
    Buzzer.buzzOff();
  }
}

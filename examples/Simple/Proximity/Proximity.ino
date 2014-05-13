/*
Example illustrates turning ON a LED each time an Object gets near your Smartphone 
using its Proximity Sensor
*/

/*Include OneSheeld Library*/
#include <OneSheeld.h>

/*Led on 13*/
int ledPin = 13;

void setup () 
{
  /*Start Communcication*/
  OneSheeld.begin();
  /*Set ledPin as OUTPUT*/
  pinMode(ledPin,OUTPUT);
}

void loop ()
{
  /*Always check the proximity of the Smartphone*/
  if(ProximitySensor.getValue()>0)
  {
    /*Put the LED On*/
    digitalWrite(ledPin,HIGH);
  }
  else
  {
    /*Put the LED Off*/
    digitalWrite(ledPin,LOW);
  }
}

/*
Example illustrates checking the temperature and when it's beyond
certain limit Turn On the LED
*/

/*Include OneSheeld Library*/
#include <OneSheeld.h>

/*Led on pin 13*/
int ledPin = 13;

void setup ()
{
  /*Start Communication*/
  OneSheeld.begin();
  /*Set ledPin as OUTPUT*/
  pinMode(ledPin,OUTPUT);
}


void loop ()
{
  /*Check the Temperature*/
  if(TemperatureSensor.getValue()<10)
  {
    /*Turn On LED*/
    digitalWrite(ledPin,HIGH);
  }
  else
  {
    /*Turn Off LED*/
    digitalWrite(ledPin,LOW);
  }
}

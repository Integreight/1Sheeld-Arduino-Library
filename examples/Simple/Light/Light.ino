/*
Example illustrates sensing the Light and when it's beyond a Limit ignite the LED 
*/


/*Include OneSheeld Library*/
#include <OneSheeld.h>

/*Led Pin on 13*/
int ledPin = 13 ;

void setup () 
{
  /*Start the Communication*/
  OneSheeld.begin();
  /*Set the ledPin as OUTPUT*/
  pinMode(ledPin,OUTPUT);
}


void loop () 
{
  /*Always check on the Light intensity*/
  if(LightSensor.getValue()<100)
  {
    /*Put On the LED*/
    digitalWrite(ledPin,HIGH);
  }
  else
  {
    /*Put Off the LED*/
    digitalWrite(ledPin,LOW);
  }
}

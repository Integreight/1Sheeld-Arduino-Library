/*
Example illustrates calculating the magnetic field surronded and when exceede a certain
Limit ignite the LED 
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
  /*Always check on the Magnetic Strength*/
  if(MagnetometerSensor.magneticStrength()>50)
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

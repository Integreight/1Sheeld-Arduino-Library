/*
Example illustrates calculating the surrounded magnetic field and when exceeds a certain
Limit, turn ON the LED!
*/


/*Include OneSheeld Library*/
#include <OneSheeld.h>

/*Led Pin on 13*/
int ledPin = 13 ;

void setup () 
{
  /*Start Communication*/
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

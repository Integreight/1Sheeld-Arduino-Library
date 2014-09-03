/*

Terminal Shield Example

This example shows an application on 1Sheeld's Terminal shield.

By using this example, you can Debug easily on Temperature sensor
and check the values in runtime.

*/

/* Include 1Sheeld library. */
#include <OneSheeld.h>

/* Fan on Pin 13. */
int fanPin = 13;
/* Reserve a byte for Temperature value. */
byte tempValue = 0 ;

void setup()
{
  /* Start communication. */
  OneSheeld.begin();
  /* Fan on pin 13. */
  pinMode(fanPin,OUTPUT);
}

void loop ()
{
  /* Always get TemperatureSensor value. */
  tempValue = TemperatureSensor.getValue();
  /* Check Temperature in the Room */
  if(tempValue > 30)
  {
    /* Turn on the fan. */
    digitalWrite(fanPin,HIGH);
    /* Display the value on Terminal. */
    Terminal.println(tempValue);
  }
  else
  {
    /* Turn off the fan. */
    digitalWrite(fanPin,LOW);
    /* Display the value on Terminal. */
    Terminal.println(tempValue);
  }
}

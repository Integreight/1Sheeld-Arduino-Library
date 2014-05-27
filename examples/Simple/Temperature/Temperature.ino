/*

Temperature Shield Example

This example shows an application on 1Sheeld's temperature shield.

By using this example, you can turn on the LED on pin 13 if the
smartphone's temperature sensor reports a certain value.

*/

/* Include 1Sheeld library. */
#include <OneSheeld.h>

/* A name for the LED on pin 13. */
int ledPin = 13;

void setup() 
{
  /* Start communication. */
  OneSheeld.begin();
  /* Set the LED pin as output. */
  pinMode(ledPin,OUTPUT);
}

void loop ()
{
   /* Always check the value of temperature sensor. */
  if(TemperatureSensor.getValue() < 10)
  {
    /* Turn on the LED. */
    digitalWrite(ledPin,HIGH);
  }
  else
  {
    /* Turn off the LED. */
    digitalWrite(ledPin,LOW);
  }
}

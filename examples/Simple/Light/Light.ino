/*

Light Shield Example

This example shows an application on 1Sheeld's light shield.

By using this example, you can turn on the LED on pin 13 if the
smartphone's light sensor reports a certain value.

OPTIONAL:
To reduce the library compiled size and limit its memory usage, you
can specify which shields you want to include in your sketch by
defining CUSTOM_SETTINGS and the shields respective INCLUDE_ define. 

*/

#define CUSTOM_SETTINGS
#define INCLUDE_LIGHT_SENSOR_SHIELD

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

void loop() 
{
  /* Always check the light intensity. */
  if(LightSensor.getValue() < 100 && LightSensor.getValue() > 0)
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

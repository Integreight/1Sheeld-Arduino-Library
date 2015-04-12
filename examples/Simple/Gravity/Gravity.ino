/*

Gravity Shield Example

This example shows an application on 1Sheeld's gravity shield.

By using this example, you can turn on some LEDs if the
smartphone's gravity sensor reaches the maximum gravity
acceleration in any of the x, y and z axises.

OPTIONAL:
To reduce the library compiled size and limit its memory usage, you
can specify which shields you want to include in your sketch by
defining CUSTOM_SETTINGS and the shields respective INCLUDE_ define. 

*/

#define CUSTOM_SETTINGS
#define INCLUDE_GRAVITY_SENSOR_SHIELD

/* Include 1Sheeld library. */
#include <OneSheeld.h>

/* A name for the LED on pin 13. */
int ledPin1 = 13;
/* A name for the LED on pin 12. */
int ledPin2 = 12;
/* A name for the LED on pin 11. */
int ledPin3 = 11;

void setup()
{
  /* Start communication. */
  OneSheeld.begin();
  /* Set LEDs 1, 2 and 3 as output. */
  pinMode(ledPin1,OUTPUT);
  pinMode(ledPin2,OUTPUT);
  pinMode(ledPin3,OUTPUT);
}

void loop()
{
  /* Check X-axis gravitational value. */
  if(GravitySensor.getX() >= 9)
  {
    /* Turn on the LED 1. */
    digitalWrite(ledPin1,HIGH);
    /* Turn off the other LEDs. */
    digitalWrite(ledPin2,LOW);
    digitalWrite(ledPin3,LOW);    
  }
  
  /* Check Y-axis gravitational value. */
  if(GravitySensor.getY() >= 9)
  {
    /* Turn on the LED 2. */
    digitalWrite(ledPin2,HIGH);
    /* Turn off the other LEDs. */
    digitalWrite(ledPin1,LOW);
    digitalWrite(ledPin3,LOW);    
  }
  
  /* Check Z-axis gravitational value. */
  if(GravitySensor.getZ() >= 9)
  {
    /* Turn on the LED 3. */
    digitalWrite(ledPin3,HIGH);
    /* Turn off the other LEDs. */
    digitalWrite(ledPin1,LOW);
    digitalWrite(ledPin2,LOW);    
  }
  
}

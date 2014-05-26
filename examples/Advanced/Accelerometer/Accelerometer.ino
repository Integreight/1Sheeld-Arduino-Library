/*

Accelerometer Shield Example

This example shows an application on 1Sheeld's accelerometer shield.

By using this example, you can grab your smartphone and strike as if
you are bowling so you can turn on the LED on pin 13.

*/

/* Include 1Sheeld library. */
#include <OneSheeld.h>

/* Variables for the accelerometer's values in 3 dimensions. */
float x;
float y;
float z;

/* A name for the LED on pin 13. */
int ledPin = 13 ;
int magnitudeThreshold = 31;

void setup() 
{
  /* Start communication. */
  OneSheeld.begin();
  /* Set the LED pin as output. */
  pinMode(ledPin,OUTPUT);
}

void loop() 
{
  /* Always get the values of the accelerometer in the 3 dimensions (X, Y and Z). */
  x=AccelerometerSensor.getX();
  y=AccelerometerSensor.getY();
  z=AccelerometerSensor.getZ();
  
  /* Check the motion of the smartphone, if it exceeded a limit, turn the LED on. */
  /* We do that by calcuating the magnitude of the 3D vectors. */
  if (sqrt((x*x)+(y*y)+(z*z)) > magnitudeThreshold)
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

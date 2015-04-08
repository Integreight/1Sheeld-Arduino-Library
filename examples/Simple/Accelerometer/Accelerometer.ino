/*

Accelerometer Shield Example

This example shows an application on 1Sheeld's accelerometer shield.

By using this example, you can turn on the LED on pin 13 if the
smartphone's accelerometer sensor reaches the maximum
acceleration in any of the x, y and z axises.

OPTIONAL:
To reduce the library compiled size and limit its memory usage, you
can specify which shields you want to include in your sketch by
defining CUSTOM_SETTINGS and the shields respective INCLUDE_ define. 

*/

#define CUSTOM_SETTINGS
#define INCLUDE_ACCELEROMETER_SENSOR_SHIELD

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
  /* Check X-axis acceleration. */
  if(AccelerometerSensor.getX() > 8)
  {
    digitalWrite(ledPin,HIGH);
  }
  else
  {  
    digitalWrite(ledPin,LOW);
  }

  /* Check Y-axis acceleration. */
  if(AccelerometerSensor.getY() > 8)
  {
    digitalWrite(ledPin,HIGH);
  }
  else
  {
    digitalWrite(ledPin,LOW);
  }

  /* Check z-Axis acceleration. */
  if(AccelerometerSensor.getZ() > 8)
  {
    digitalWrite(ledPin,HIGH);
  }
  else
  {
    digitalWrite(ledPin,LOW);
  }
}

/*

Terminal Shield Example

This example shows an application on 1Sheeld's terminal shield.

By using this example, you can debug your Arduino code easily and send
temperature sensor data and check the values on our app.

OPTIONAL:
To reduce the library compiled size and limit its memory usage, you
can specify which shields you want to include in your sketch by
defining CUSTOM_SETTINGS and the shields respective INCLUDE_ define. 

*/

#define CUSTOM_SETTINGS
#define INCLUDE_TERMINAL_SHIELD
#define INCLUDE_TEMPERATURE_SENSOR_SHIELD

/* Include 1Sheeld library. */
#include <OneSheeld.h>

/* Fan on Pin 13. */
int fanPin = 13;
/* Reserve a byte for Temperature value. */
int tempValue = 0;

void setup()
{
  /* Start communication. */
  OneSheeld.begin();
  /* Fan on pin 13. */
  pinMode(fanPin,OUTPUT);
}

void loop()
{
  /* Always get Temperature sensor value. */
  tempValue = TemperatureSensor.getValue();
  /* Check the temperature in the room. */
  if(tempValue > 30)
  {
    /* Turn on the fan. */
    digitalWrite(fanPin,HIGH);
    /* Display the value on the terminal. */
    Terminal.println(tempValue);
  }
  else
  {
    /* Turn off the fan. */
    digitalWrite(fanPin,LOW);
    /* Display the value on the terminal. */
    Terminal.println(tempValue);
  }
}

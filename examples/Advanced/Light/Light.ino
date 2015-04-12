/*

Light Shield Example

This example shows an application on 1Sheeld's light shield.

By using this example, you can control a LED with the light
sensor on your smartphone. Simply, the LED value will fade
depending on the intensity of the light in the room.

PS: For the sake of this example, put your smartphone in
place where it can detect the maximum light intensity in
the room first as it use it to calibrate.

OPTIONAL:
To reduce the library compiled size and limit its memory usage, you
can specify which shields you want to include in your sketch by
defining CUSTOM_SETTINGS and the shields respective INCLUDE_ define. 

*/

#define CUSTOM_SETTINGS
#define INCLUDE_LIGHT_SENSOR_SHIELD


/* Include 1Sheeld library.*/ 
#include <OneSheeld.h>

/* Maximum light intensity. */ 
long maxLightIntensity=0;
/* Ratio between the maximum value of fading and the maximum value got by the light sensor. */
float ratio = 0;
/* The current value of the LED. */
long ledValue = 0;
/* The current value from the light sensor. */
long lightValue;
/* A name for a LED on pin 10. */
int ledPin = 10;

void setup()
{
  /* Start communication. */
  OneSheeld.begin();
  /* Set the LED pin as output. */
  pinMode(ledPin,OUTPUT);
}

void loop()
{
  /*
  Don't put the phone on direct light as it will be a very large
  value which will not let the example work properly.
  */

  /* If the sensor value is larger than maximum, make it the maximum. */
  if(LightSensor.getValue() > maxLightIntensity)
  {
    maxLightIntensity = LightSensor.getValue();
    ratio = 255 / (float) maxLightIntensity;
  }
  /* Get the light values that will be processed. */
  lightValue = LightSensor.getValue();
  /* If the light value is bigger than the maximum then let it be the maximum. */
  if(lightValue > maxLightIntensity)
  {
    lightValue = maxLightIntensity;
  }

  /*Do some processing of the value of the led with the ratio calculated. */
  ledValue= 255 - lightValue * ratio;
  
  if(ledValue < 10)
  {
    /* Turn off the LED if its value is less than 10. */ 
    analogWrite(ledPin,0);
  }
  else
  {
    /* Set the LED to a certain value. */
    analogWrite(ledPin,ledValue);  
  }
  
}

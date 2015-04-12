/*

Orientation Shield Example

This example shows an application on 1Sheeld's orientation shield.

By using this example, you can allign a portrait on
the wall using your smartphone's orientation sensor
along with the buzzer shield.

PS: X-axis ranges from 0 to 360 degrees, Y-axis
ranges from -180 to 180 degrees and Z-axis ranges
from -90 to 90.

OPTIONAL:
To reduce the library compiled size and limit its memory usage, you
can specify which shields you want to include in your sketch by
defining CUSTOM_SETTINGS and the shields respective INCLUDE_ define. 

*/

#define CUSTOM_SETTINGS
#define INCLUDE_ORIENTATION_SENSOR_SHIELD
#define INCLUDE_BUZZER_SHIELD

/* Include 1Sheeld library. */
#include <OneSheeld.h>

void setup() 
{
  /* Start communication. */
  OneSheeld.begin();
}

void loop() 
{
  /* Always get the Y-axis and Z-axis values and check if they are near zero. */
  if (OrientationSensor.getY() > -1 && OrientationSensor.getY() < 1 && OrientationSensor.getZ() > -1 && OrientationSensor.getZ() < 1)
  {
      /* Turn on the buzzer. */
      Buzzer.buzzOn();
  }
  /* If they are not aligned, turn off the buzzer. */
  else
  {
    Buzzer.buzzOff();
  }
}

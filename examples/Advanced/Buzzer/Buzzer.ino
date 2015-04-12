/*

Buzzer Shield Example

This example shows an application on 1Sheeld's buzzer shield.

By using this example, you can buzz each and every time you get
near your smartphone using the phone's proximity sensor.

OPTIONAL:
To reduce the library compiled size and limit its memory usage, you
can specify which shields you want to include in your sketch by
defining CUSTOM_SETTINGS and the shields respective INCLUDE_ define. 

*/

#define CUSTOM_SETTINGS
#define INCLUDE_BUZZER_SHIELD
#define INCLUDE_PROXIMITY_SENSOR_SHIELD

/* Include 1Sheeld library. */
#include <OneSheeld.h>

void setup() 
{
  /* Start communication. */
  OneSheeld.begin();
}

void loop()
{
  /* Check out if something is near the phone, buzz immediately. */
  if (ProximitySensor.getValue() == 0)
  {
    /* Always buzz when there's something near the phone. */
    Buzzer.buzzOn();
  }
  else 
  {
    /* Turn of the buzzer. */
    Buzzer.buzzOff();
  }
}

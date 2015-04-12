/*

LED Shield Example

This example shows an application on 1Sheeld's LED shield.

By using this example, you can turn on control the app's
LED shield.

OPTIONAL:
To reduce the library compiled size and limit its memory usage, you
can specify which shields you want to include in your sketch by
defining CUSTOM_SETTINGS and the shields respective INCLUDE_ define. 

*/

#define CUSTOM_SETTINGS
#define INCLUDE_LED_SHIELD

/* Include 1Sheeld library. */
#include <OneSheeld.h>

void setup()
{
  /* Start communication. */
  OneSheeld.begin();
}

void loop() 
{
  /* Turn on the LED. */
  LED.setHigh();
  OneSheeld.delay(1000);
  /* Turn off the LED. */
  LED.setLow();
  OneSheeld.delay(1000);
}

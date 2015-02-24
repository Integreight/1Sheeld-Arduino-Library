/*

LED Shield Example

This example shows an application on 1Sheeld's LED shield.

By using this example, you can turn on control the app's
LED shield.

*/

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

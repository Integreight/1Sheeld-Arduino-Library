/*

Buzzer Shield Example

This example shows an application on 1Sheeld's buzzer shield.

By using this example, you can buzz each and every time you get
near your smartphone using the phone's proximity sensor.

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

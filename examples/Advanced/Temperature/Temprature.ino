/*

Temperature Shield Example

This example shows an application on 1Sheeld's Temperature shield.

By using this example, you can make the buzzer sound
when the value of the smartphone's temperature sensor
exceeds a certain limit.

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
    /* Buzz if the temperature exceeds 20 degrees celsius. */ 
    if (Temperature.getValue() >= 20)
    {
      /* Turn on the buzzer. */
      Buzzer.buzzOn();
      /* Wait for 1 second. */
      delay(1000);
      /* Turn of the buzzer. */  
      Buzzer.buzzOff();
    }
}




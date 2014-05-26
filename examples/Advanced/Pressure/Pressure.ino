/*

Pressure Shield Example

This example shows an application on 1Sheeld's pressure shield.

By using this example, you can send a SMS when the value
of the smartphone's pressure sensor exceeds a certain limit.

*/

/* Include 1Sheeld library. */
#include <OneSheeld.h>

/* Define a boolean flag. */
boolean isMessageSent = false;

void setup() 
{
  /* Start communication. */
  OneSheeld.begin();
}

void loop() 
{
  /* Always read the pressure value and check if it exceeds a certain value. */
  if (PressureSensor.getValue() > 1008)
  {
    /* Check that we haven't sent the SMS already. */
    if (!isMessageSent)
    {
      /* Send the SMS. */
      SMS.send("1234567890","Pressure is getting high in here!");
      /* Set the flag. */
      isMessageSent = true;
    }
  }
  else
  {
    /* Reset the flag. */
    isMessageSent = false;
  }
}

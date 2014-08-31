/*

Data-Logger Shield Example

This example shows an application on 1Sheeld's Data-Logger shield.

By using this example, you can check the variation of the temperature 
at your place by logging the data for 24 hours.

*/

/* Include 1Sheeld library. */
#include <OneSheeld.h>

/* Variable for the hours. */
byte hour=0;
/* Boolean to stop logging. */
bool stopped=false;

void setup () 
{
  /* Start communication. */
  OneSheeld.begin();
  /* Start logger shield. */
  Logger.start();
  /* Start clock shield. */
  Clock.begin();
}

void loop ()
{
  /* Always get hours. */
  hour=Clock.getHours();
  /* Add temperature values as column in file. */
  Logger.add("Temperature Celsuis",TemperatureSensor.getValue());
  /* Log the data in rows in file. */
  Logger.log();
  /* Once the day ends stop logging and generate the file. */
  if(hour==0 && !stopped)
  {
    /* Stop logging. */
    Logger.stop();
    /* Set stopped boolean to true. */
    stopped=true;
  }
  else
  {
    /* Reset stopped boolean to false. */
    stopped=false;
  }
}

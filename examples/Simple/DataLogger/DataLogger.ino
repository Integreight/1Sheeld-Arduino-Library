/*

Data-Logger Shield Example

This example shows an application on 1Sheeld's data logger shield.

By using this example, you can check the variation of the room's temperature 
at your place by logging each 20 successive readings in separate files.

*/

/* Include 1Sheeld library. */
#include <OneSheeld.h>

/* Variable for the hours. */
int counter = 0;
/* Button on pin 12. */
int buttonPin = 12;
/* Boolean to start logging. */ 
bool startFlag = false;

void setup() 
{
  /* Start communication. */
  OneSheeld.begin();
  /* Save any previous logged values. */
  Logger.stop();
  /* Set buttonPin as input. */
  pinMode(buttonPin,INPUT);
}

void loop()
{
  if(digitalRead(buttonPin) == HIGH)
  {
    /* First insure to save previous logged values. */
    Logger.stop();
    /* Set a delay. */
    delay(500);
    /* Start logging in a new file. */
    Logger.start("Mic values");
    /* Set startFlag. */
    startFlag = true;
  }

  /* Check logging started. */
  if(startFlag)
  {
    /* Add temperature values as a column in the file. */
    Logger.add("Decibles",Mic.getValue());
    /* Log the row in the file. */
    Logger.log();  
    /* Delay for 1 second. */
    delay(1000);
    /* Increment counter. */
    counter++;
    /* Stop logging after 20 readings and save the file. */
    if(counter==20)
    {
      /* Save the logging file. */
      Logger.stop();
      /* Reset counter. */
      counter=0;
      /* Start Logging again. */
      Logger.start("Mic values");
    }
  }
  
}
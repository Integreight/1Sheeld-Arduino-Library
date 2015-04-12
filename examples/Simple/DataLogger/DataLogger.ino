/*

Data-Logger Shield Example

This example shows an application on 1Sheeld's data logger shield.

By using this example, you can check the variation of noise level using 
Mic shield by logging each 20 successive readings in separate CSV files.

OPTIONAL:
To reduce the library compiled size and limit its memory usage, you
can specify which shields you want to include in your sketch by
defining CUSTOM_SETTINGS and the shields respective INCLUDE_ define. 

*/

#define CUSTOM_SETTINGS
#define INCLUDE_DATA_LOGGER_SHIELD
#define INCLUDE_MIC_SHIELD

/* Include 1Sheeld library. */
#include <OneSheeld.h>

/* Reserve a counter. */
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
  /* Check if button pressed. */
  if(digitalRead(buttonPin) == HIGH)
  {
    /* First insure to save previous logged values. */
    Logger.stop();
    /* Set a delay. */
    OneSheeld.delay(500);
    /* Start logging in a new CSV file. */
    Logger.start("Mic values");
    /* Set startFlag. */
    startFlag = true;
  }

  /* Check logging started. */
  if(startFlag)
  {
    /* Add noise level values as a column in the CSV file. */
    Logger.add("Decibles",Mic.getValue());
    /* Log the row in the file. */
    Logger.log();  
    /* Delay for 1 second. */
    OneSheeld.delay(1000);
    /* Increment counter. */
    counter++;
    /* Stop logging after 20 readings and save the CSV file. */
    if(counter==20)
    {
      /* Save the logging CSV file. */
      Logger.stop();
      /* Reset counter. */
      counter=0;
      /* Start Logging again. */
      Logger.start("Mic values");
    }
  }
  
}
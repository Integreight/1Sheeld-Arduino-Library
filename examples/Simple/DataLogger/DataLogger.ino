/*

Data-Logger Shield Example

This example shows an application on 1Sheeld's data logger shield.

By using this example, you can check the variation of the room's temperature 
at your place by logging the data for 12 hours.

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
  /* Start logger shield. */
  Logger.stop();
  /* Set buttonPin as input. */
  pinMode(buttonPin,INPUT);
  pinMode(13,OUTPUT);
  digitalWrite(13,HIGH);
}

void loop()
{
  if(digitalRead(buttonPin)== HIGH)
  {
    /* First insure to stop last logged data. */
    Logger.stop();
    /* Set a Delay. */
    delay(500);
    /* Start Logging. */
    Logger.start();
    /* Set startFlag. */
    startFlag = true;
    
  }

  /* Check Logging started. */
  if(startFlag)
  {
    /* Add temperature values as a column in the file. */
    Logger.add("Decibles",Mic.getValue());
    /* Log the row in the file. */
    Logger.log();  
    /* Delay 1000 msec. */
    delay(1000);
    /* Increment counter. */
    counter++;

  }
  
  /* Once the half day ends stop logging and generate the file(12 hours=12*60*60 seconds ). */
  if(counter==12*60*60)
  {
    /* Stop logging. */
    Logger.stop();
    /* Reset counter. */
    counter=0;
  }
}
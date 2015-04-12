/*

Skype Shield Example

This example shows an application on 1Sheeld's Skype shield.

By using this example, you can call one of your Skype's
contacts when you press the button on pin 12.

OPTIONAL:
To reduce the library compiled size and limit its memory usage, you
can specify which shields you want to include in your sketch by
defining CUSTOM_SETTINGS and the shields respective INCLUDE_ define. 

*/

#define CUSTOM_SETTINGS
#define INCLUDE_SKYPE_SHIELD

/* Include 1Sheeld library. */ 
#include <OneSheeld.h>

/* Define a boolean flag. */
boolean didWeCall = false;
/* A name for the button on pin 12. */
int buttonPin = 12;

void setup() 
{
  /* Start communication. */
  OneSheeld.begin();
  /* Set the button pin as input. */
  pinMode(buttonPin,INPUT);
}

void loop() 
{
  if (digitalRead(buttonPin) == HIGH)
  {
    if(!didWeCall)
    {
      /* Call one of your Skype's contacts. */
      Skype.call("echo123");  
      /* Set the flag. */
      didWeCall = true;
    }
  }
  else
  {
    /* Reset the flag. */
    didWeCall = false;
  }
}


/*

Face Detector Shield Example

This example shows an application on 1Sheeld's face detector shield.

By using this example, you can unlock a door by winking three times to
the front camera.
 
OPTIONAL:
To reduce the library compiled size and limit its memory usage, you
can specify which shields you want to include in your sketch by
defining CUSTOM_SETTINGS and the shields respective INCLUDE_ define. 

*/

#define CUSTOM_SETTINGS
#define INCLUDE_FACE_DETECTOR_SHIELD
#define INCLUDE_TERMINAL_SHIELD

/* Include 1Sheeld library. */
#include <OneSheeld.h>

/* A name for the LED on pin 13. */
int ledPin = 13;

/* A name for the relay on pin 12. */
int relayPin = 12;

/* A name for the winks counter. */
int counter = 0;

void setup() 
{
  /* Start communication. */
  OneSheeld.begin();
  /* Set the LED pin as output. */
  pinMode(ledPin,OUTPUT);
  /* Set the relay pin as output. */
  pinMode(relayPin,OUTPUT); 
}

void loop() 
{
  /* Get the first face and check if it winks. */
  if(FaceDetector.getVisibleFace(0).getLeftEyeOpenProbability()==0)
  {
    /* Turn on the LED when winking. */
    digitalWrite(ledPin,HIGH);
    /* Count the winks. */
    counter++;
    /* A slight delay. */
    OneSheeld.delay(1000);
  }else
  {
    /* Turn off the LED. */
    digitalWrite(ledPin,LOW);
  }

  /* Check the number of winks. */
  if(counter == 3)
  {
    /* Send success. */
    Terminal.println("Success");
    /* Open the lock. */
    digitalWrite(relayPin,HIGH);
    /* Reset counter. */
    counter=0;
  }
}
/*

Camera Shield Example

This example shows an application on 1Sheeld's camera shield.

By using this example, you can take a photo using your phone's
camera each time you press the hardware push button placed on
pin 12.

OPTIONAL:
To reduce the library compiled size and limit its memory usage, you
can specify which shields you want to include in your sketch by
defining CUSTOM_SETTINGS and the shields respective INCLUDE_ define. 

*/

#define CUSTOM_SETTINGS
#define INCLUDE_CAMERA_SHIELD
#define INCLUDE_TWITTER_SHIELD

/* Include 1Sheeld library. */
#include <OneSheeld.h>

/* A name for the button on pin 12. */
int buttonPin = 12;
/* A name for the LED on pin 13. */
int ledPin = 13;

void setup()
{
  /* Start communication. */
  OneSheeld.begin();
  /* Set the button pin as input. */
  pinMode(buttonPin,INPUT);
  /* Set the LED pin as output. */
  pinMode(ledPin,OUTPUT);
}

void loop()
{
  /* Always check the button state. */
  if(digitalRead(buttonPin) == HIGH)
  {
    /* Turn on the LED. */
    digitalWrite(ledPin,HIGH);
    /* Turn on the camera flash. */
    Camera.setFlash(ON);
    /* Take the picture. */
    Camera.rearCapture();
    /* Wait for 10 seconds. */
    OneSheeld.delay(10000);
    /* Post the picture on Twitter. */
    Twitter.tweetLastPicture("Posted by @1Sheeld and @Arduino");
  }
  else
  {
    /* Turn off the LED. */
    digitalWrite(ledPin,LOW);
  }
    
}

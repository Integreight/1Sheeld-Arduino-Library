/*

Camera Shield Example

This example shows an application on 1Sheeld's camera shield.

By using this example, you can take a photo using your phone's
camera each time you press the hardware push button placed on
pin 12.

*/

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
    /* Wait for 300 ms. */
    delay(300);
  }
  else
  {
    /* Turn off the LED. */
    digitalWrite(ledPin,LOW);
  }
    
}

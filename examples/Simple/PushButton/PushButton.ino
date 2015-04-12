/*

Push Button Shield Example

This example shows an application on 1Sheeld's push button shield.

By using this example, you can turn on the LED on pin 13
when you press the app's push button.

OPTIONAL:
To reduce the library compiled size and limit its memory usage, you
can specify which shields you want to include in your sketch by
defining CUSTOM_SETTINGS and the shields respective INCLUDE_ define. 

*/

#define CUSTOM_SETTINGS
#define INCLUDE_PUSH_BUTTON_SHIELD

/* Include 1Sheeld library. */
#include <OneSheeld.h>

/* A name for the LED on pin 13. */
int ledPin = 13;

void setup()
{
  /* Start communication. */
  OneSheeld.begin();
  /* Set the LED pin as output. */
  pinMode(ledPin,OUTPUT);
}

void loop()
{
  /* Always check if the push button is pressed. */
  if(PushButton.isPressed())
  {
    /* Turn on the LED. */
    digitalWrite(ledPin,HIGH);
  }
  else
  {
    /* Turn on the LED. */
    digitalWrite(ledPin,LOW);
  }

}




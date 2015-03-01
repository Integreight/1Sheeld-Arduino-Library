/*

Keyboard Shield Example

This example shows an application on 1Sheeld's keyboard shield.

By using this example, you can turn on LEDs using certain characters.

*/

/* Include 1Sheeld library. */
#include <OneSheeld.h>

/* LED on pin 13. */
int ledPin = 13;

void setup() 
{
  /* Start communication. */
  OneSheeld.begin();
  /* Set the LED as output. */
  pinMode(ledPin,OUTPUT);
  /* Keyboard callBack function. */
  AsciiKeyboard.setOnButtonChange(&keyboardFunction);
}

void loop()
{}

/* Function to be invoked once a new character is pressed. */
void  keyboardFunction(char data)
{
  /* Check on the incoming character. */
  if(data == 'A')
  {
    /* Turn on the LED. */
    digitalWrite(ledPin,HIGH);
  }
  else
  {
    /* Turn off the LED.*/
    digitalWrite(ledPin,LOW);
  }
}

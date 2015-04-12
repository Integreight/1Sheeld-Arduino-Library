/*

Keypad Shield Example

This example shows an application on 1Sheeld's keypad shield.

By using this example, you can turn on some LEDs if you
pressed the first 4 buttons of our app's keypad shield.

OPTIONAL:
To reduce the library compiled size and limit its memory usage, you
can specify which shields you want to include in your sketch by
defining CUSTOM_SETTINGS and the shields respective INCLUDE_ define. 

*/

#define CUSTOM_SETTINGS
#define INCLUDE_KEYPAD_SHIELD

/* Include 1Sheeld library. */
#include <OneSheeld.h>

/* A name for the LED on pin 13. */
int ledPin1 = 13;
/* A name for the LED on pin 12. */
int ledPin2 = 12;
/* A name for the LED on pin 11. */
int ledPin3 = 11;
/* A name for the LED on pin 10. */
int ledPin4 = 10;

void setup() 
{
  /* Start communication. */
  OneSheeld.begin();
  /* Set LEDs 1, 2, 3 and 4 as output. */
  pinMode(ledPin1,OUTPUT);
  pinMode(ledPin2,OUTPUT);
  pinMode(ledPin3,OUTPUT);
  pinMode(ledPin4,OUTPUT);
}

void loop()
{
  /* If keypad's button 1 is pressed. */
  if(Keypad.isRowPressed(0) && Keypad.isColumnPressed(0))
  {
    /* Turn on the LED 1. */
    digitalWrite(ledPin1,HIGH);
    /* Turn off the other LEDs. */
    digitalWrite(ledPin2,LOW);
    digitalWrite(ledPin3,LOW);
    digitalWrite(ledPin4,LOW);
  }
  /* If keypad's button 2 is pressed. */
  else if(Keypad.isRowPressed(0) && Keypad.isColumnPressed(1))
  {
    /* Turn on the LED 2. */
    digitalWrite(ledPin2,HIGH);
    /* Turn off the other LEDs. */
    digitalWrite(ledPin1,LOW);
    digitalWrite(ledPin3,LOW);
    digitalWrite(ledPin4,LOW);
  }
  /* If keypad's button 3 is pressed. */
   else if(Keypad.isRowPressed(0) && Keypad.isColumnPressed(2))
  {
    /* Turn on the LED 3. */
    digitalWrite(ledPin3,HIGH);
    /* Turn off the other LEDs. */
    digitalWrite(ledPin1,LOW);
    digitalWrite(ledPin2,LOW);
    digitalWrite(ledPin4,LOW);
  }
  /* If keypad's button 4 is pressed. */
   else if(Keypad.isRowPressed(1) && Keypad.isColumnPressed(0))
  {
    /* Turn on the LED 4. */
    digitalWrite(ledPin4,HIGH);
    /* Turn off the other LEDs. */
    digitalWrite(ledPin1,LOW);
    digitalWrite(ledPin2,LOW);
    digitalWrite(ledPin3,LOW);
  }
  else
  {
    /* Turn off all of LEDs. */
    digitalWrite(ledPin1,LOW);
    digitalWrite(ledPin2,LOW);
    digitalWrite(ledPin3,LOW);
    digitalWrite(ledPin4,LOW);
  }
}

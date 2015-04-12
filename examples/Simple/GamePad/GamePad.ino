/*

Gamepad Shield Example

This example shows an application on 1Sheeld's gamepad shield.

By using this example, you can light up some LEDs placed on
different Arduino pins using the gamepad in our app.

OPTIONAL:
To reduce the library compiled size and limit its memory usage, you
can specify which shields you want to include in your sketch by
defining CUSTOM_SETTINGS and the shields respective INCLUDE_ define. 

*/

#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_SHIELD

/* Include 1Sheeld library. */
#include <OneSheeld.h>

void setup() 
{
  /* Start communication. */
  OneSheeld.begin();
  /* Set some pins as output. */
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  
}

void loop() 
{
  /* Always check the status of gamepad buttons. */
  if (GamePad.isUpPressed())
  {
    /* Turn on the LED on pin 13 when up is pressed. */
    digitalWrite(13,HIGH);
    /* Turn off the other LEDs. */
    digitalWrite(12,LOW);
    digitalWrite(11,LOW);
    digitalWrite(10,LOW);
  }
 if(GamePad.isDownPressed())
  {
    /* Turn on the LED on pin 12 when down is pressed. */
    digitalWrite(12,HIGH);
    /* Turn off the other LEDs. */
    digitalWrite(13,LOW);
    digitalWrite(11,LOW);
    digitalWrite(10,LOW);
  }
 if (GamePad.isUpPressed()&&GamePad.isOrangePressed())
  {
    /* Turn on the LED on pin 11 when up and orange are pressed. */
    digitalWrite(11,HIGH);
    /* Turn off the other LEDs. */
    digitalWrite(13,LOW);
    digitalWrite(12,LOW);
    digitalWrite(10,LOW);
  }
 if (GamePad.isDownPressed()&&GamePad.isRedPressed())
  {
    /* Turn on the LED on pin 10 when down and red are pressed. */
    digitalWrite(10,HIGH);
    /* Turn off the other LEDs. */
    digitalWrite(13,LOW);
    digitalWrite(12,LOW);
    digitalWrite(11,LOW);
  }
}


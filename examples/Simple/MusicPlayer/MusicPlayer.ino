/*

Music Player Shield Example

This example shows an application on 1Sheeld's music player shield.

By using this example, you can play and pause music from
your smartphone using 2 hardware push buttons.

OPTIONAL:
To reduce the library compiled size and limit its memory usage, you
can specify which shields you want to include in your sketch by
defining CUSTOM_SETTINGS and the shields respective INCLUDE_ define. 

*/

#define CUSTOM_SETTINGS
#define INCLUDE_MUSIC_PLAYER_SHIELD

/* Include 1Sheeld library. */
#include <OneSheeld.h>

/* A name for the button on pin 12. */
int buttonPin1 = 12;
/* A name for the button on pin 11. */
int buttonPin2 = 11;
/* A name for the LED on pin 13. */
int ledPin = 13;

void setup() 
{
  /* Start communication. */
  OneSheeld.begin();
  /* Set the LED pin as output. */
  pinMode(ledPin,OUTPUT);
  /* Set the two buttons pins as input. */
  pinMode(buttonPin1,INPUT);
  pinMode(buttonPin2,INPUT);
  
}

void loop()
{
  /* Always check button 1 state. */
  if(digitalRead(buttonPin1) == HIGH)
  { 
      /* Turn on the LED. */
       digitalWrite(ledPin,HIGH);
       /* Set the volume. */
       MusicPlayer.setVolume(5);
       /* Turn on the music. */
       MusicPlayer.play();
       /* Wait for 300 ms. */
       OneSheeld.delay(300);
  }
  /* Always check button 2 state. */
  if(digitalRead(buttonPin2) == HIGH)
  { 
      /* Turn off the LED. */
      digitalWrite(ledPin,LOW);
      /* Turn off the music. */
      MusicPlayer.pause();
      /* Wait for 300 ms. */
      OneSheeld.delay(300);
      
  }
}

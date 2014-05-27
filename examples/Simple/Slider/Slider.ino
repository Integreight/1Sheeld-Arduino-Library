/*

Slider Shield Example

This example shows an application on 1Sheeld's slider shield.

By using this example, you can control the frequency
of a piezo speaker using the app's slider.

*/

/* Include 1Sheeld library. */
#include <OneSheeld.h>

/* Define a variable to hold the value of the slider. */
int value;
/* A name for the Speaker on pin 11. */
int speakerPin = 11;

void setup() 
{
  /* Start communication. */
  OneSheeld.begin();
  /* Set speakerPin as output. */
  pinMode(speakerPin,OUTPUT);
}

void loop() 
{
  /* Always get the value of the slider and output it as PWM to pin 11. */
  value = Slider.getValue();
  analogWrite(speakerPin,value);
}

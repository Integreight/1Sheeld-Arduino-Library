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

void setup() 
{
  /* Start communication. */
  OneSheeld.begin();
  /* Set pin 11 as output. */
  pinMode(11,OUTPUT);
}

void loop() 
{
  /* Always get the value of the slider and output it as PWM to pin 11. */
  value = Slider.getValue();
  analogWrite(11,value);
}

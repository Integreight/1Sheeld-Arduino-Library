/*

Color Shield Example

This example shows an application on 1Sheeld's color shield.

By using this example, you can control and RGB led colors using color shield and 
PWM and change it's "RGB" color according grabbed color.

OPTIONAL:
To reduce the library compiled size and limit its memory usage, you
can specify which shields you want to include in your sketch by
defining CUSTOM_SETTINGS and the shields respective INCLUDE_ define. 

*/

#define CUSTOM_SETTINGS
#define INCLUDE_COLOR_DETECTOR_SHIELD

/* Include 1Sheeld library. */
#include <OneSheeld.h>

/* Reserve PWM pins for RGB LED. */  
int redPin = 9;
int greenPin =10;
int bluePin = 11;

void setup() {
  // put your setup code here, to run once:
  /* Start communication. */
  OneSheeld.begin();
  /* Set pins mode OUTPUT for RGB LED. */
  pinMode(redPin, OUTPUT); 
  pinMode(greenPin, OUTPUT); 
  pinMode(bluePin, OUTPUT);
  /* Enable normal operating mode for color shield. */
  ColorDetector.enableNormalOperation();
  /* Set Palette to get 8 different colors only. */
  ColorDetector.setPalette(_3_BIT_RGB_PALETTE); 
}

void loop() {
  // put your main code here, to run repeatedly:
  /* Check if there's a new color grabbed. */
  if(ColorDetector.isNewColorReceived())
  {
    /* Get red, blue and green component values. */
    byte redValue = ColorDetector.getLastColor().getRed();
    byte greenValue = ColorDetector.getLastColor().getGreen();
    byte blueValue = ColorDetector.getLastColor().getBlue();
    
    /* Output values on LED pins. */
    digitalWrite(redPin,redValue);
    digitalWrite(greenPin,greenValue);
    digitalWrite(bluePin,blueValue);    
  }
}

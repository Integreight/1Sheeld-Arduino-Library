/*

Color Detector Shield Example

This example shows an application on 1Sheeld's color detector shield.

By using this example, you can control the color of a RGB LED according
to the color read by our color detector shield.

OPTIONAL:
To reduce the library compiled size and limit its memory usage, you
can specify which shields you want to include in your sketch by
defining CUSTOM_SETTINGS and the shields respective INCLUDE_ define. 

*/

#define CUSTOM_SETTINGS
#define INCLUDE_COLOR_DETECTOR_SHIELD

/* Include 1Sheeld library. */
#include <OneSheeld.h>

/* Reserve PWM pins for the RGB LED. */  
int redPin = 9;
int greenPin =10;
int bluePin = 11;

void setup() {
  /* Start communication. */
  OneSheeld.begin();
  /* Set the RGB LED pins as output. */
  pinMode(redPin, OUTPUT); 
  pinMode(greenPin, OUTPUT); 
  pinMode(bluePin, OUTPUT);
  /* Set the color detection palette to get only 8 different colors instead of the default 16 million. */
  ColorDetector.setPalette(_3_BIT_RGB_PALETTE);
}

void loop() {
  /* Check if there's a new color received. */
  if(ColorDetector.isNewColorReceived())
  {
    /* Read the last received color and save it locally. */
    Color readColor = ColorDetector.getLastColor();

    /* Get red, blue and green components values. */
    byte redValue = readColor.getRed();
    byte greenValue = readColor.getGreen();
    byte blueValue = readColor.getBlue();
    
    /* Output the values on the RGB LED pins. */
    digitalWrite(redPin,redValue);
    digitalWrite(greenPin,greenValue);
    digitalWrite(bluePin,blueValue);    
  }
}

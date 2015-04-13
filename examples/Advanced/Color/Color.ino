/*

Color Shield Example

This example shows an application on 1Sheeld's color shield.

By using this example, by using your camera you can teach your children colors 
by pointing the camera to the color and your smartphone will say the color.

OPTIONAL:
To reduce the library compiled size and limit its memory usage, you
can specify which shields you want to include in your sketch by
defining CUSTOM_SETTINGS and the shields respective INCLUDE_ define. 

*/

#define CUSTOM_SETTINGS`
#define INCLUDE_COLOR_DETECTOR_SHIELD
#define INCLUDE_TEXT_TO_SPEECH_SHIELD

/* Include 1Sheeld library. */
#include <OneSheeld.h>

/* Red Color. */
unsigned long redColor = 0xFF0000;
/* Blue Color. */
unsigned long blueColor = 0x0000FF;
/* Green Color. */
unsigned long greenColor = 0x00FF00;


void setup() {
  // put your setup code here, to run once:
  /* Start communication. */
  OneSheeld.begin();
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
    /* Compare colors and if red say RED. */
    if(ColorDetector.getLastColor()== redColor)
    {
      /* Say RED. */
      TextToSpeech.say("Red");
    }
    else if(ColorDetector.getLastColor()== blueColor)
    {
      /* Say BLUE. */
      TextToSpeech.say("Blue");
    }
    else if(ColorDetector.getLastColor()== greenColor)
    {
      /* Say GREEN. */
      TextToSpeech.say("Green");
    }
  }
}

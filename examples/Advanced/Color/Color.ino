/*

Color Detector Shield Example

This example shows an application on 1Sheeld's color detector shield.

By using this example, you can play a game with your friends by tracking 
a black track on a white paper and win by not letting 1Sheeld guide your 
direction twice.

OPTIONAL:
To reduce the library compiled size and limit its memory usage, you
can specify which shields you want to include in your sketch by
defining CUSTOM_SETTINGS and the shields respective INCLUDE_ define. 

*/

#define CUSTOM_SETTINGS
#define INCLUDE_TERMINAL_SHIELD
#define INCLUDE_COLOR_DETECTOR_SHIELD
#define INCLUDE_TEXT_TO_SPEECH_SHIELD

/* Include 1Sheeld library. */
#include <OneSheeld.h>

/* Reserve a varriable for black color. */
unsigned long black = 0x00000000;

void setup() 
{
  /* Start communincation. */  
  OneSheeld.begin();
  /* Subscribe to setOnSelected Callback as once color shield 
  is selected Arduino sends data to be processed by color shield. */
  ColorDetector.setOnSelected(&selected);
}

void loop() 
{}

/* OnSelected function. */
void selected()
{
  /* Set color palette for a 1 bit gray scale. */
  ColorDetector.setPalette(_1_BIT_GRAYSCALE_PALETTE);
  /* Enable full operation mode .*/
  ColorDetector.enableFullOperation();
  /* Grab most dominant color in each patch. */
  ColorDetector.setCalculationMode(MOST_DOMINANT_COLOR);
  /* Subscribe when a new color is received. */
  ColorDetector.setOnNewColor(&newColor);
}

/* onNewColor function. */
void newColor(Color one,Color two,Color three,Color four,Color five,Color six,Color seven,Color eight,Color nine)
{
  /* Check first and third patches. */
  if (three == black && one != black)
  {
    /* Guide me to the Right. */
    TextToSpeech.say("Turn Right");
    OneSheeld.delay(300);
  }
  else if (one == black && three != black)
  {
    /* Guide me to the Left. */
    TextToSpeech.say("Turn Left");
    OneSheeld.delay(300);
  }
}

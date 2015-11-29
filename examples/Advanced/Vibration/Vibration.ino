/*

Vibration Shield Example

This example shows an application on 1Sheeld's vibration shield.

By using this example, you can make your phone vibrate with a pattern and repeat that pattern forever with a given delay 

OPTIONAL:
To reduce the library compiled size and limit its memory usage, you
can specify which shields you want to include in your sketch by
defining CUSTOM_SETTINGS and the shields respective INCLUDE_ define. 

*/
#define CUSTOM_SETTINGS
#define INCLUDE_VIBRATION_SHIELD

/* Include 1Sheeld library. */
#include <OneSheeld.h>

int arraySize = 6;
int pattern[6] = {1000,2000,1000,2000,1000,2000};
int delayTime = 15000;
void setup() {
  OneSheeld.begin();
}

void loop() {
  /* You can send a pattern of vibes */
 
  //That pattern makes the phone vibrate for a second and wait for 2 seconds for 3 times
  //send you pattern array size first then the pattern itself to the vibrate function
  Vibration.start(arraySize,pattern);

  //wait for 12 seconds
  OneSheeld.delay(12000);

  //if you need that pattern to repeat itself with a delay of 15 seconds
  Vibration.start(arraySize,pattern,delayTime);

  //Wait a minute (60 seconds)
  OneSheeld.delay(60000);

  //stop
  Vibration.stop();

  /*  IMPORTANT NOTES
   *  The pattern must be int[]
   *  Max pattern length is 127
   *  Each element in the array range between 0 and 65534
   *  Time unit used is Milliseconds
   *  Delay time must be int and range between 0 and 65534
   *  Any call to Vibration.start() cancels the prior calls of it
   *  -which means any repetitive vibration will stop-
   */
  
}

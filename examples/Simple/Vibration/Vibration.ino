/*

Vibration Shield Example

This example shows an application on 1Sheeld's vibration shield.

By using this example, you can make your phone vibrate for a given amount of time.

OPTIONAL:
To reduce the library compiled size and limit its memory usage, you
can specify which shields you want to include in your sketch by
defining CUSTOM_SETTINGS and the shields respective INCLUDE_ define. 

*/

#define CUSTOM_SETTINGS
#define INCLUDE_VIBRATION_SHIELD

/* Include 1Sheeld library. */
#include <OneSheeld.h>
void setup() {
  OneSheeld.begin();
}

void loop() {
  /* Make a one time vibration that lasts for 1 second 
     Notice that the time-unit is in Milliseconds*/
  Vibration.start(1000);

  //Wait for 8 seconds
  OneSheeld.delay(8000);

  /* Make a vibration that lasts for 1 second
     and repeat itself with a delay of 5 seconds*/
  Vibration.start(1000,5000);

  //wait for 13 seconds
  OneSheeld.delay(13000);

  //To stop any repetitive vibration
  Vibration.stop();
}

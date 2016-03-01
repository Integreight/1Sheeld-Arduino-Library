/*

Vibration Shield Example

This example shows an application on 1Sheeld's vibration shield.

By using this example, you can make your phone vibrate in 2 different
patterns. 

OPTIONAL:
To reduce the library compiled size and limit its memory usage, you
can specify which shields you want to include in your sketch by
defining CUSTOM_SETTINGS and the shields respective INCLUDE_ define. 

*/

#define CUSTOM_SETTINGS
#define INCLUDE_VIBRATION_SHIELD

/* Include 1Sheeld library. */
#include <OneSheeld.h>

/* This pattern waits for 1 second and vibrate for 2, 3 times. */
int patternOne[6] = {1000,2000,1000,2000,1000,2000};
int patternOneSize = 6;

/* A sample heart beat pattern. */
int patternTwo[4] = {100, 250, 100, 400};
int patternTwoSize = 4;

void setup() {
  /* Start communication. */
  OneSheeld.begin();
}

void loop() {
  /* Vibrate as the first pattern once. */
  Vibration.start(patternOneSize,patternOne);

  /* Wait for 9 seconds. */
  OneSheeld.delay(9000);

  /* Vibrate as the second pattern and keep repeating the vibration every 300 ms. */
  Vibration.start(patternTwoSize,patternTwo,300);

  /* Wait for 10 seconds. */
  OneSheeld.delay(10000);

  /* Stop the vibration. */
  Vibration.stop();
}

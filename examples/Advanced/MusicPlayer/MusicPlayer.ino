/*

Music Player Shield Example

This example shows an application on 1Sheeld's music player shield.

By using this example, you can play and stop music from
your smartphone at certain times.

OPTIONAL:
To reduce the library compiled size and limit its memory usage, you
can specify which shields you want to include in your sketch by
defining CUSTOM_SETTINGS and the shields respective INCLUDE_ define. 

*/

#define CUSTOM_SETTINGS
#define INCLUDE_MUSIC_PLAYER_SHIELD
#define INCLUDE_CLOCK_SHIELD

/* Include 1Sheeld library. */
#include <OneSheeld.h>

/* Define some variables for the timer. */
int seconds, minutes, hours;

void setup()
{
  /* Start communication. */
  OneSheeld.begin();
  /* Start the clock shield. */
  Clock.queryDateAndTime();
}

void loop() 
{
  /* Always get the time. */
  seconds = Clock.getSeconds();
  minutes = Clock.getMinutes();
  hours   = Clock.getHours();
  
  /* Play music at 8 am. */
  if (hours == 8 && minutes == 0 && seconds == 00)
  {
    /* Play the music. */
    MusicPlayer.play();
    /* Set the volume. */
    MusicPlayer.setVolume(5);
  }
  /* Stop music at 9 am. */
  else if(hours == 9 && minutes == 0 && seconds == 00)
  {
    /* Turn off the music. */
    MusicPlayer.stop();
  }
  
}

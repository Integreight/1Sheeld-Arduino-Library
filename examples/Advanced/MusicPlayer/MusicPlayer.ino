/*

Music Player Shield Example

This example shows an application on 1Sheeld's music player shield.

By using this example, you can play and stop music from
your smartphone at certain times.

*/

/* Include 1Sheeld library. */
#include <OneSheeld.h>

/* Define some variables for the timer. */
int seconds, minutes, hours;

void setup()
{
  /* Start communication. */
  OneSheeld.begin();
  /* Start the clock shield. */
  Clock.begin();
}

void loop() 
{
  /* Always get the time. */
  seconds = Clock.getSeconds();
  minutes = Clock.getMinutes();
  hours   = Clock.getHours();
  
  /* Play music at 8 am. */
  if (hours==8 && minutes==0 && seconds==00)
  {
    /* Play the music. */
    MusicPlayer.play();
    /* Set the volume. */
    MusicPlayer.setVolume(5);
  }
  /* Stop music at 9 am. */
  else if(hours==9 && minutes==0 && seconds==00)
  {
    /* Turn off the music. */
    MusicPlayer.stop();
  }
  
}

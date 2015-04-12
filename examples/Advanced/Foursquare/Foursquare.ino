/*

Foursquare Shield Example

This example shows an application on 1Sheeld's Foursquare shield.

By using this example, you can check-in at the Great Pyramids
of Giza (Egypt) using the Foursquare shield along with the GPS shield.

OPTIONAL:
To reduce the library compiled size and limit its memory usage, you
can specify which shields you want to include in your sketch by
defining CUSTOM_SETTINGS and the shields respective INCLUDE_ define. 

*/

#define CUSTOM_SETTINGS
#define INCLUDE_FOURSQUARE_SHIELD
#define INCLUDE_GPS_SHIELD

/* Include 1Sheeld library.*/
#include <OneSheeld.h>

/* Define a variable to check-in only once.*/
boolean didIcheckedIn = false;

void setup() 
{
  /* Start communication. */
  OneSheeld.begin();
}

void loop() 
{
  /* Always check if the GPS coordinates is in a range of 100 meters from
     the coordinates of the pyramids then make a check-in on Foursquare. */
  if (GPS.isInRange(31.134358,29.979175,100))
  {
    /* Check only once. */
    if (!didIcheckedIn)
    {
      /* Check-in at the pyramids. */
      Foursquare.checkIn("4b9f7a50f964a520422537e3","Whao! what a great place.");
      /* Reset the value of the variable. */
      didIcheckedIn = true;
    }
  }  
}


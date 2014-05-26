/*

Foursquare Shield Example

This example shows an application on 1Sheeld's Foursquare shield.

By using this example, you can check-in at the Great Pyramids
of Giza (Egypt) using the Foursquare shield along with the GPS shield.

*/

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
  /* Always get the GPS coordinates and if it is near the coordinates of the pyramids then
  make a check-in on Foursquare. */
  if (GPS.getLongitude() == 31.134358 && GPS.getLattitude() == 29.979175)
  {
    /* Check only once. */
    if (didIcheckedIn == false)
    {
      /* Check-in at the pyramids. */
      Foursquare.checkIn("4b9f7a50f964a520422537e3","Whao! what a great place.");
      /* Reset the value of the variable. */
      didIcheckedIn = true;
    }
  }  
}


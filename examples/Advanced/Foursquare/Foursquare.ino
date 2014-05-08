/*
Example illustrates Checking in at the Great Pyramids in Giza (Egypt) using the Foursquare 
Shield Application and the GPS Shield 
*/

/*Including OneSheeld Library*/
#include <OneSheeld.h>

/*Reserve a variable to check in once*/
boolean checkedIn= false;

void setup () 
{
  /*Start Communication*/
  OneSheeld.begin();
}


void loop () 
{
  /*Always get the GPS coordinates and if it is same as the coordinates of the Pyramids
  check in*/
  if (GPS.getLongitude()==31.134358 && GPS.getLattitude()==29.979175)
  {
    /*Check only once*/
    if (checkedIn == false)
    {
      /*Check in at the Pyramids*/
      Foursquare.checkIn("4b9f7a50f964a520422537e3","WoW what a great Place");
      /*Reset the value of the variable*/
      checkedIn = true;
    }
  }  
}


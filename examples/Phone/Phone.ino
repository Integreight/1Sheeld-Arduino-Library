/*
Example illustrates Phone shield to check out if the music player at your place was playing
or if there is someone at the place and check what's is going on with the help of Clock shield 
*/


/*Including OneSheeld Library*/
#include <OneSheeld.h>


void setup () 
{
  /*Start UART communication on baudrate 57600*/
  OneSheeld.begin();
  /*Start the Clock*/
  Clock.begin();
}


void loop () 
{
  /*At 3PM give me a call*/
  if (Clock.getSeconds()==00 && Clock.getMinutes()==00 && Clock.getHours()==15)
  {
    /*Call my phone*/
    Phone.call("+0201286077028");
  }
}

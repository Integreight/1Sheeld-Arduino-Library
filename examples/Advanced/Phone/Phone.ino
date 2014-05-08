/*
Example illustrates Phone shield to check out if the music player at your place was playing
or if there is someone at the place and check what's is going on with the help of Clock shield 
*/


/*Include OneSheeld Library*/
#include <OneSheeld.h>

/*Reserve a boolean*/
boolean called = false;
void setup () 
{
  /*Start Communication*/
  OneSheeld.begin();
  /*Start the Clock*/
  Clock.begin();
}


void loop () 
{
  /*At 3PM give me a call*/
  if (Clock.getSeconds()==00 && Clock.getMinutes()==00 && Clock.getHours()==15)
  {
    /*Check if called don't call again*/
    if (called = false)
    {
      /*Call my phone*/
      Phone.call("+0201286077028");
      /*Stop Calling*/
      called = true;
    }
    
  }
}

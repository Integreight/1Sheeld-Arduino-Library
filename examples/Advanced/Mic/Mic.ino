/*
Example illustrates the use of the Smart Phones Mic checking out the sound 
in a certain room and when the sound exceeded a certain limit send a tweet 
*/

/*Include OneSheeld Library*/
#include <OneSheeld.h>

/*Reserve a boolean*/
boolean tweetSent = false;

void setup ()
{
  /*Start Communication*/
  OneSheeld.begin();
}


void loop()
{
  /*Always get the noise level from the Mic and check if it exceeds a certain value*/
  if(Mic.getValue()>100)
  {
  	if(tweetSent == false)
  	{
	  	/*Send the tweet*/
	    Twitter.updateStatus("We Are JAMMING ;)"); 
	    tweetSent = true;
  	}
    
  }
  
}

/*
Example illustrates the use of the Smartphone Mic checking out the sound 
in a certain room when the sound exceeded a certain limit, tweet. 
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

  /*Reset the Boolean Flag*/
  if(Mic.getValue()<100)
  {
    tweetSent = false;
  }
  
}

/*

Mic Shield Example

This example shows an application on 1Sheeld's mic shield.

By using this example, you can tweet when the sound level in
the room exceeds a certain threshold.

*/

/* Include 1Sheeld library. */
#include <OneSheeld.h>

/* Define a boolean flag. */
boolean isTweetSent = false;

void setup()
{
  /* Start communication. */
  OneSheeld.begin();
}

void loop()
{
  /* Always get the noise level from the mic and check if it exceeds a certain value. */
  if(Mic.getValue() > 100)
  {
  	if(!isTweetSent)
  	{
	  	/*Send the tweet*/
	    Twitter.updateStatus("We are making some noise! sent from @1Sheeld"); 
      /* Set the flag. */
	    isTweetSent = true;
  	}
    
  }

  /* Reset the flag. */
  if(Mic.getValue() < 100)
  {
    isTweetSent = false;
  }
  
}

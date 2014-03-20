/*
Example illustrates the use of the Smart Phones Mic checking out the sound 
in a certain room and when the sound exceeded a certain limit send a tweet 
*/

/*including the OneSheeld Library*/
#include <OneSheeld.h>

void setup ()
{
  /*Start the UART communication on baudrate 57600*/
  OneSheeld.begin();
}


void loop()
{
  /*always get the value of the Mic and check if it exceeds a certain value*/
  if(Mic.getValue()>100)
  {
    /*send a tweet*/
    Twitter.updateStatus("We Are JAMMING ;)"); 
  }
  
}

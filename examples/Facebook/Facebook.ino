/*
Example illustrates updating status on Facebook by pressing a button when you get back Home
*/

/*Including OneSheeld Library*/
#include <OneSheeld.h>

void setup () 
{
  /*Start UART communication on baudrate 57600*/
  OneSheeld.begin();
  /*Let pin 13 as INPUT*/
  pinMode(13,INPUT);
}

void loop ()
{
  /*Always check pin 13*/
  if(digitalRead(13)==HIGH)
  {
    /*Twitter also can be used instead of Facebook*/
    /*Update your status on Facebbok*/
    Facebook.updateStatus("Home Sweet Home");
  }
}

/*
Example illustrates the Skype shield Application when you press the button you will call 
a certain skype account you set in the sketch
*/

/*Including OneSheeld Library*/ 
#include <OneSheeld.h>

/*Reserve a variable for not always calling in loop*/
boolean called=false;
void setup () 
{
  /*Start UART communication on buadrate 57600*/
  OneSheeld.begin();
  /*Set pin 13 as INPUT*/
  pinMode(13,INPUT);
}


void loop () 
{
  /*Always check pin 13 if it's high Skype the account*/
  if (digitalRead(13)==HIGH)
  {
    /*To call only once and not go on calling while looping*/
    if(called=false)
    {
      /*Call echo123*/
      Skype.call("echo123");  
      /*Reset the variable*/
      called=true;
    }
  }
}


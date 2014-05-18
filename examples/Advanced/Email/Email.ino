/*
Example Illustrates Sending an Email using the Toggle Shield button 
when pressed send the Email
*/

/*Including OneSheeld Library*/
#include <OneSheeld.h>


void setup () 
{
  /*Start Communication*/
  OneSheeld.begin();
  /*Function to check the Change of the button*/
  PushButton.setOnChange(& buttonChange);
}

void loop()
{}


void buttonChange(byte buttonValue)
{
  /*Check the buttons Value*/
  if(buttonValue != 0)
  {
    Email.send("eslam.mohamed.fathy@gmail.com","Greetings","Hi Eslam, From Integreight");
  }
}
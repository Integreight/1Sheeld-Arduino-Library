/*

Email Shield Example

This example shows an application on 1Sheeld's email shield.

By using this example, you can send an email when the app's
Push button is pressed.

*/

/* Include 1Sheeld library. */
#include <OneSheeld.h>

void setup() 
{
  /* Start communication.*/
  OneSheeld.begin();
  /* Call a specific function when the push button is pressed or unpressed. */
  PushButton.setOnButtonStatusChange(&onButtonStatusChanged);
}

void loop()
{
	/* Do nothing. */
}

void onButtonStatusChanged(bool isPressed)
{
  /* Check the buttons status. */
  if(isPressed)
  {
  	/* Send an email. */
    Email.send("example@example.com","Button pressed!","Hi, someone pressed the button!");
  }
}
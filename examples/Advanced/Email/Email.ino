/*

Email Shield Example

This example shows an application on 1Sheeld's email shield.

By using this example, you can send an email when the app's
Push button is pressed.

OPTIONAL:
To reduce the library compiled size and limit its memory usage, you
can specify which shields you want to include in your sketch by
defining CUSTOM_SETTINGS and the shields respective INCLUDE_ define. 

*/

#define CUSTOM_SETTINGS
#define INCLUDE_EMAIL_SHIELD
#define INCLUDE_PUSH_BUTTON_SHIELD

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
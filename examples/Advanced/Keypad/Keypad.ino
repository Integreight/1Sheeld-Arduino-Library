/*

Keypad Shield Example

This example shows an application on 1Sheeld's keypad shield.

By using this example, you can use the app's keypad to enter
a password (ex: 1234) to do an action, in this case blinking
a LED.

DISCLAIMER: This Example is not for REAL SECURITY SYSTEMS and
we don't hold responsibility in case something went wrong. Use
it at your own risk.

OPTIONAL:
To reduce the library compiled size and limit its memory usage, you
can specify which shields you want to include in your sketch by
defining CUSTOM_SETTINGS and the shields respective INCLUDE_ define. 

*/

#define CUSTOM_SETTINGS
#define INCLUDE_KEYPAD_SHIELD

/* Include 1Sheeld library. */
#include <OneSheeld.h>

/* Define an iterator. */ 
int iterations = 0;
/* A name for the LED on pin 13. */
int ledPin = 13;

void setup() 
{
  /* Start communication. */
  OneSheeld.begin();
  /* Set the LED as output. */
  pinMode(ledPin,OUTPUT);
}

void loop()
{
  /* Check if "1" is pressed, iterate one time. */ 
  if(iterations == 0 && isOnePressed())
  {
     iterations++;
  }
  /* Check if "2" is pressed, iterate one time. */ 
  else if (iterations == 1 && isTwoPressed())
  {
     iterations++;
  }
  /* Check if "3" is pressed, iterate one time. */ 
  else if (iterations == 2 && isThreePressed())
  {
     iterations++;
  }
  /* Check if "4" is pressed, iterate one time. */
  else if(iterations == 3 && isFourPressed())
  {
     iterations++;
  }
  /* Check if any other button is pressed, reset iterations. */
  else if(isOtherButtonPressed())
  {
    iterations = 0;
  }
     
   /* Check if the number of iterations is 4, blink the LED. */
   if(iterations == 4)
   {    
        digitalWrite(ledPin,HIGH);
        OneSheeld.delay(500);
        digitalWrite(ledPin,LOW);
        /* Reset the iterator. */
        iterations = 0;
   }
}
 
/* Helper functions check if a certain button is pressed by checking its row and column. */

boolean isOnePressed(){
  return Keypad.isRowPressed(0) && Keypad.isColumnPressed(0);
}

boolean isTwoPressed(){
  return Keypad.isRowPressed(0) && Keypad.isColumnPressed(1);
}

boolean isThreePressed(){
  return Keypad.isRowPressed(0) && Keypad.isColumnPressed(2);
}

boolean isFourPressed(){
  return Keypad.isRowPressed(1) && Keypad.isColumnPressed(0);
}

boolean isOtherButtonPressed(){
  return ((Keypad.isAnyColumnPressed() || Keypad.isAnyColumnPressed()) && !isOnePressed() && !isTwoPressed() && !isThreePressed() && !isFourPressed());
}


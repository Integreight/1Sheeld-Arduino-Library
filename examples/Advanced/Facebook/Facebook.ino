/*

Facebook Shield Example

This example shows an application on 1Sheeld's Facebook shield.

By using this example, you can update your Facebook status
everyday at 8 am.

*/


/* Include 1Sheeld library. */
#include <OneSheeld.h>
/* Include LiquidCrystal library. */
#include <LiquidCrystal.h>

/* Initialize the LCD interfacing pins. */
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

/* Define some variables for the time. */
int hours, minutes, seconds;

void setup() 
{
  /* Start communication. */
  OneSheeld.begin();
  /* Start clock shield. */
  Clock.begin();
  /* Set up the LCD's columns and rows. */ 
  lcd.begin(16, 2);
  pinMode(9,OUTPUT);
  analogWrite(9,0);
}

void loop()
{
  hours   = Clock.getHours();
  minutes = Clock.getMinutes();
  seconds = Clock.getSeconds();

  /*Check the clock*/
  if(hours == 8 && minutes == 0 && seconds == 0)
  {
    /* Update my Facebook status. */ 
    Facebook.post("Good morning!");
    /* Update the LCD screen. */
    lcd.print("Status updated!");
    /* Delay for 2 seconds. */
    delay(2000);
    /* Clear the LCD. */
    lcd.clear();
  }
}

/*

Facebook Shield Example

This example shows an application on 1Sheeld's Facebook shield.

By using this example, you can update your Facebook status
everyday at 8 am.

OPTIONAL:
To reduce the library compiled size and limit its memory usage, you
can specify which shields you want to include in your sketch by
defining CUSTOM_SETTINGS and the shields respective INCLUDE_ define. 

*/

#define CUSTOM_SETTINGS
#define INCLUDE_FACEBOOK_SHIELD
#define INCLUDE_CLOCK_SHIELD


/* Include 1Sheeld library. */
#include <OneSheeld.h>
/* Include LiquidCrystal library. */
#include <LiquidCrystal.h>

/* Initialize the LCD interfacing pins. */
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

/* Define some variables for the time. */
int hours, minutes, seconds;
/* LCD contrast level on pin 9. */
int lcdContrast = 9;

void setup() 
{
  /* Start communication. */
  OneSheeld.begin();
  /* Start clock shield. */
  Clock.queryDateAndTime();
  /* Set up the LCD's columns and rows. */ 
  lcd.begin(16, 2);
  /*Set lcd contrast pin as output. */ 
  pinMode(lcdContrast,OUTPUT);
  /* Use a range from 0 till 255 to control the contrast of the LCD. */
  analogWrite(lcdContrast,0);
}

void loop()
{
  hours   = Clock.getHours();
  minutes = Clock.getMinutes();
  seconds = Clock.getSeconds();

  /* Check the clock. */
  if(hours == 8 && minutes == 0 && seconds == 0)
  {
    /* Update my Facebook status. */ 
    Facebook.post("Good morning!");
    /* Update the LCD screen. */
    lcd.print("Status updated!");
    /* Delay for 2 seconds. */
    OneSheeld.delay(2000);
    /* Clear the LCD. */
    lcd.clear();
  }
}

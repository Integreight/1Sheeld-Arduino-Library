/*

Clock Shield Example

This example shows an application on 1Sheeld's clock shield.

By using this example, you can send an SMS to a friend on his
birthday and update your status on Facebook when the phone's
time reaches a certain time you specify.

OPTIONAL:
To reduce the library compiled size and limit its memory usage, you
can specify which shields you want to include in your sketch by
defining CUSTOM_SETTINGS and the shields respective INCLUDE_ define. 

*/

#define CUSTOM_SETTINGS
#define INCLUDE_CLOCK_SHIELD
#define INCLUDE_SMS_SHIELD
#define INCLUDE_FACEBOOK_SHIELD

/* Include 1Sheeld library. */
#include <OneSheeld.h>

/* Define some variables for the date and time. */
int hour, minute, second, day, month, year;

void setup()
{
  /* Start communication. */
  OneSheeld.begin();
  /* Start the clock shield. */
  Clock.queryDateAndTime();
}

void loop() 
{
  /* Always get the date and time. */
  hour = Clock.getHours();
  minute = Clock.getMinutes();
  second = Clock.getSeconds();
  day = Clock.getDay();
  month = Clock.getMonth();
  year = Clock.getYear();
  
  /* If the date is my friends's birthday date send me 
     SMS at 3 pm that day and post on Facebook. */
  if(hour == 15 && minute == 0 && second == 0 && day == 6 && month == 2 && year == 2014)
  {
    /* Send the SMS. */
    SMS.send("1234567890","Happy birthday buddy, sent from 1Sheeld.");
    /* Update my Facebook status. */ 
    Facebook.post("It is my friend birthday.");
    /* Delay 2 sec. */
    OneSheeld.delay(2000);
  }
} 

/*

Phone Shield Example

This example shows an application on 1Sheeld's phone shield.

By using this example, you can open your home's door
for a friend by calling a smartphone connected to
1Sheeld.

OPTIONAL:
To reduce the library compiled size and limit its memory usage, you
can specify which shields you want to include in your sketch by
defining CUSTOM_SETTINGS and the shields respective INCLUDE_ define. 

*/

#define CUSTOM_SETTINGS
#define INCLUDE_PHONE_SHIELD

/* Include 1Sheeld library. */
#include <OneSheeld.h>

/* Phone number to check if it called. */
char callingNumber[]= "1234567890";
/* A name for the LED on pin 13. */
int ledPin = 13;
/* A name for the relay on pin 12. */
int relayPin = 12;

void setup()
{
  /* Start communication. */
  OneSheeld.begin();
  /* Set the LED pin as output. */
  pinMode(ledPin,OUTPUT);
  /* Set the relay pin as output. */
  pinMode(relayPin,OUTPUT);
}

void loop() 
{
    /* Check if the phone is ringing. */
    if(Phone.isRinging())
    {
        /* Check if the phone number calling is the same as our variable. */
        if(strcmp(Phone.getNumber(),callingNumber) == 0)
       {
          /* Turn on the LED. */
          digitalWrite(ledPin,HIGH);
          /* Turn on the relay to open the door. */
          digitalWrite(relayPin,HIGH);
       }  
    }    
}

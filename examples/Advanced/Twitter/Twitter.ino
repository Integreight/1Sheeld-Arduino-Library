/*

Twitter Shield Example

This example shows an application on 1Sheeld's Twitter shield.

By using this example, you can flash a LED once a certain keyword
is mentioned on Twitter.

OPTIONAL:
To reduce the library compiled size and limit its memory usage, you
can specify which shields you want to include in your sketch by
defining CUSTOM_SETTINGS and the shields respective INCLUDE_ define. 

*/

#define CUSTOM_SETTINGS
#define INCLUDE_TWITTER_SHIELD

/* Include 1Sheeld library. */
#include <OneSheeld.h>

/* A name for led on pin 13. */
int ledPin = 13;
/* A variable to track number of tracked tweets returned. */
int trackingCounter = 0;

void setup() {
  /* Start communication. */
  OneSheeld.begin();
  /* Set the LED pin as output. */
  pinMode(ledPin,OUTPUT);
  /* Subscribe to setOnSelected event for the Twitter shield. */
  Twitter.setOnSelected(&shieldSelection);
  /* Subscribe to onNewTweet event. */
  Twitter.setOnNewTweet(&myTweet);
}

void loop() 
{
  /* Leave the loop empty. */
}

void shieldSelection()
{
  /* Track keyword 1Sheeld on Twitter. */
  Twitter.trackKeyword("1Sheeld");
}

void myTweet(char * userName , char * userTweet)
{
    /* Check if the tweet has 1Sheeld keyword. */
    if(strstr(userTweet,"1Sheeld")!=0)
    {
      /* Turn on the LED. */
      digitalWrite(ledPin,HIGH);
      /* Use OneSheeld delay for better performance. */
      OneSheeld.delay(1000);
      /* Increment the counter. */
      trackingCounter++;
      /* Turn off the LED. */
      digitalWrite(ledPin,LOW);
    }
    /* Check if the counter reached three times. */
    if(trackingCounter == 3)
    {
      /* Stop tracking the word 1Sheeld. */
      Twitter.untrackKeyword("1Sheeld");
      /* Reset the counter. */
      trackingCounter = 0;
    }
}

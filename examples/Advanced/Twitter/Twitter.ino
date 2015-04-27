/*

Twitter Shield Example

This example shows an application on 1Sheeld's Twitter shield.

By using this example, you can track a certain keyword over Twitter and 
every time a tweet has the keyword it will return back to you with the 
user name and the tweet and also an LED will turn on for three
times then it will stop tracking the keyword.

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
  /* Set ledPin to OUTPUT. */
  pinMode(ledPin,OUTPUT);
  /* Subscribe to callback on selected as once you select the shield
  it will invoke your function which is in this example track keyword. */
  Twitter.setOnSelected(&shieldSelection);
  /* Subscribe to callback on new tweet to invoke your function once a new
  tweet comes. */
  Twitter.setOnNewTweet(&myTweet);
}

void loop() 
{}

void shieldSelection()
{
  /* Track keyword 1Sheeld on twitter. */
  Twitter.trackKeyword("1Sheeld");
}

void myTweet(char * userName , char * userTweet)
{
    /* Check if the tweet got the keyword turn on the LED for 1 second. */
    if(strstr(userTweet,"1Sheeld")!=NULL)
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
    /* Check if the counter reached three times stop tracking the word. */
    if(trackingCounter == 3)
    {
      /* Stop tracking the word 1Sheeld. */
      Twitter.untrackKeyword("1Sheeld");
      /* Reset the counter. */
      trackingCounter = 0;
    }
}

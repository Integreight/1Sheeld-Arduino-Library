/*
Example illustrates sending Notifications by pressing a button 
*/

/*Including OneSheeld Library*/
#include <OneSheeld.h>


/*Button on pin 12*/
int buttonPin = 12;
/*Led on pin 13*/
int ledPin = 13;

void setup () 
{
  /*Start Communication*/
  OneSheeld.begin();
  /*Set buttonPin as INPUT*/
  pinMode(buttonPin,INPUT);
  /*Set ledPin as OUTPUT*/
  pinMode(ledPin,OUTPUT);
}

void loop ()
{
  /*Always check the button state*/
  if(digitalRead(buttonPin)==HIGH)
  {
    /*Turn LED On*/
    digitalWrite(ledPin,HIGH);
    /*Send Notification to your Phone*/
    Notification.notifyPhone("we are Notifying the Phone");
  }
  else
  {
    /*Turn LED Off*/
    digitalWrite(ledPin,LOW);
  }
}

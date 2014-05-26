/*
Example illustrates cheking in using Foursquare by pressing a button 
*/

/*Including OneSheeld Library*/
#include <OneSheeld.h>

int buttonPin = 12;
int ledPin = 13;
void setup () 
{
  /*Start Communication*/
  OneSheeld.begin();
  /*Set buttonPin INPUT*/
  pinMode(buttonPin,INPUT);
  /*Set ledPin OUTPUT*/
  pinMode(ledPin,OUTPUT);
}

void loop ()
{
  /*Always check button State*/
  if(digitalRead(buttonPin)==HIGH)
  {
    /*Turn LED On*/
    digitalWrite(ledPin,HIGH);
    /*Checking in at My Work :INTEGRIEGHT*/
    Foursquare.checkIn("511759f2e4b0b0ae6ed91067","Back To Work");
  }
  else
  {
    digitalWrite(ledPin,LOW);
  }
}

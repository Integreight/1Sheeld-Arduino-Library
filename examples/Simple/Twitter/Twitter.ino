/*
Example illustrates updating status on Twitter by pressing a button

/*Including OneSheeld Library*/
#include <OneSheeld.h>

/*button on pin12*/
int buttonPin = 12;
/*led on pin 13*/
int ledPin = 13;
void setup () 
{
  /*Start communication*/
  OneSheeld.begin();
  /*Set buttonPin as INPUT*/
  pinMode(buttonPin,INPUT);
  /*Set ledPin as OUTPUT*/
  pinMode(ledPin,OUTPUT);
}

void loop ()
{
  /*Always check pin 13*/
  if(digitalRead(buttonPin)== HIGH)
  {
    /*Turn LED On*/
    digitalWrite(ledPin,HIGH);
    /*Facebook also can be used instead of Twitter*/
    /*Update your status on Twitter*/
    Twitter.tweet("Home Sweet Home");
    delay(300);
  }
  else
  {
    digitalWrite(ledPin,LOW);
  }
}
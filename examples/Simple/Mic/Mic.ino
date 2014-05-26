/*
Example illustrates the noise level using the mic of your
Smartphone and when exceeds certain limit, LED on pin 13 goes ON!
*/

/*Include OneSheeld Library*/
#include <OneSheeld.h>

int ledPin = 13;
void setup () 
{
  /*Start communication*/
  OneSheeld.begin();
  /*Set ledPin OUTPUT*/
  pinMode(ledPin,OUTPUT);
}


void loop ()
{
  /*Always check the Noise level from your Smartphone mic*/
  if(Mic.getValue()>80)
  {
    /*LED on*/
    digitalWrite(ledPin,HIGH);
  }
  else 
  {
    /*LED off*/
    digitalWrite(ledPin,LOW);
  }
}

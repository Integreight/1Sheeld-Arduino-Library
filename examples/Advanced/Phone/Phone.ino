/*
Example illustartes Calling your Smartphone which is at your home to open the door 
for your friend  
*/

/*Include OneSheeld Library*/
#include <OneSheeld.h>

/*Phone Number to check On*/
char arr[]= "01119611432";
/*Led on pin 13*/
int ledPin = 13;
/*Relay on pin 12*/
int relayPin = 12;

void setup ()
{
  /*Start Communication*/
  OneSheeld.begin();
  /*Set pin 13 as OUTPUT*/
  pinMode(ledPin,OUTPUT);
  /*Set pin 12 as OUTPUT*/
  pinMode(relayPin,OUTPUT);
}


void loop () 
{
    /*Check if the Phone is Ringing*/
    if(Phone.isRinging())
    {
        /*Check on the Phone Number*/
        if(strcmp(Phone.getNumber(),arr)==0)
       {
          /*Turn On the LED*/
          digitalWrite(ledPin,HIGH);
          /*Apply 5V to Relay to open the door*/
          digitalWrite(relayPin,HIGH);
       }  
    }
       
}

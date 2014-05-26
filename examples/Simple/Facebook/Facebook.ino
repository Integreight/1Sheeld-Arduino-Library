/*
Example illustrates updating status on Facebook by pressing a button 
*/

/*Include OneSheeld Library*/
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
    /*Turn on the Led*/
    digitalWrite(ledPin,HIGH);
    /*Twitter also can be used instead of Facebook*/
    /*Update your status on Facebbok*/
    Facebook.post("Home Sweet Home");
  }
  else
  {
    digitalWrite(ledPin,LOW);
  }

}

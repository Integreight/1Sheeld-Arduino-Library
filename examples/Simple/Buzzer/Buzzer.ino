/*
Example illustrates buzzing each time you press the pushbutton (hardware)
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
    /*Buzz*/
    Buzzer.buzzOn();
    /*Turn on the Led*/
    digitalWrite(ledPin,HIGH);
  }
  else
  {
    Buzzer.buzzOff();
    /*Turn Off the Led*/
    digitalWrite(ledPin,LOW);
  }
  
}

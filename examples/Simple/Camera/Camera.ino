/*
Example illustrates taking pictures each time you press the pushbutton (hardware)
*/

/*Include OneSheeld Library*/
#include <OneSheeld.h>

/*Button on pin 12*/
int buttonPin = 12 ;
/*Led on pin 13*/
int ledPin = 13;

void setup ()
{
  /*Start communication*/
  OneSheeld.begin();
  /*Set the buttonPin as INPUT*/
  pinMode(buttonPin,INPUT);
  /*Set the ledPin as OUTPUT*/
  pinMode(ledPin,OUTPUT);
}

void loop ()
{
    /*Check the State of the Button*/
    if(digitalRead(buttonPin)==HIGH)
    {
      /*Turn on the LED*/
      digitalWrite(ledPin,HIGH);
      /*Set the Flash in the Camera*/
      Camera.setFlash(ON);
      /*Take the Picture*/
      Camera.rearCapture();
    }
    else
    {
      /*Turn off the Led*/
      digitalWrite(ledPin,LOW);
    }
    
}

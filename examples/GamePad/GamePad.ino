/*
Example illustrates the GamePad Shield application by lighting some LEDs when pressing
specific buttons or pressing multiple buttons at the same time
*/

/*Include OneSheeld Library*/
#include <OneSheeld.h>



void setup () 
{
  /*Start UART communication on baudrate 57600*/
  OneSheeld.begin();
  /*Set some pins OUTPUT*/
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  
}


void loop () 
{
  /*Always check on the values comming from the GamePad application*/
  if (GamePad.isUpPressed())
  {
    /*Ignite LED on pin 13 when Up is Pressed*/
    digitalWrite(13,HIGH);
    digitalWrite(12,LOW);
    digitalWrite(11,LOW);
    digitalWrite(10,LOW);
  }
  else if(GamePad.isDownPressed())
  {
    /*Ignite LED on pin 12 when Down is Pressed*/
    digitalWrite(12,HIGH);
    digitalWrite(13,LOW);
    digitalWrite(11,LOW);
    digitalWrite(10,LOW);
  }
  else if (GamePad.isUpPressed()&&GamePad.isOrangePressed())
  {
    /*Ignite LED on pin 11 when Up and A is Pressed*/
    digitalWrite(11,HIGH);
    digitalWrite(13,LOW);
    digitalWrite(12,LOW);
    digitalWrite(10,LOW);
  }
  else if (GamePad.isDownPressed()&&GamePad.isRedPressed())
  {
    /*Ignite LED on pin 10 when Down and B is Pressed*/
    digitalWrite(10,HIGH);
    digitalWrite(13,LOW);
    digitalWrite(12,LOW);
    digitalWrite(11,LOW);
  }
}


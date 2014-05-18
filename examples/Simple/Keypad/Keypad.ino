/*
Example illustrates Turning ON some LEDs while pressing on certain Numbers
on the Keypad 
*/


/*Include OneSheeld Library*/
#include <OneSheeld.h>

/*Leds on pins 13,12,11,10*/
int ledPin1 = 13;
int ledPin2 = 12;
int ledPin3 = 11;
int ledPin4 = 10;

void setup () 
{
  /*Start Communication*/
  OneSheeld.begin();
  /*Set ledPin1,2,3,4 as OUTPUT*/
  pinMode(ledPin1,OUTPUT);
  pinMode(ledPin2,OUTPUT);
  pinMode(ledPin3,OUTPUT);
  pinMode(ledPin4,OUTPUT);
  
}

void loop ()
{
  /*LED1 On when press Number 1*/
  if(Keypad.isRowPressed(0)&&Keypad.isColumnPressed(0))
  {
    digitalWrite(ledPin1,HIGH);
    digitalWrite(ledPin2,LOW);
    digitalWrite(ledPin3,LOW);
    digitalWrite(ledPin4,LOW);
  }
  /*LED2 On when press Numer 2*/
  else if(Keypad.isRowPressed(0)&&Keypad.isColumnPressed(1))
  {
    digitalWrite(ledPin2,HIGH);
    digitalWrite(ledPin1,LOW);
    digitalWrite(ledPin3,LOW);
    digitalWrite(ledPin4,LOW);
  }
  /*LED3 On when press Number 3*/
   else if(Keypad.isRowPressed(0)&&Keypad.isColumnPressed(2))
  {
    digitalWrite(ledPin3,HIGH);
    digitalWrite(ledPin1,LOW);
    digitalWrite(ledPin2,LOW);
    digitalWrite(ledPin4,LOW);
  }
  /*LED4 On when press Number 4*/
   else if(Keypad.isRowPressed(1)&&Keypad.isColumnPressed(0))
  {
    digitalWrite(ledPin4,HIGH);
    digitalWrite(ledPin1,LOW);
    digitalWrite(ledPin2,LOW);
    digitalWrite(ledPin3,LOW);
  }
  else
  {
    /*Turn all the LEDs Off*/
    digitalWrite(ledPin1,LOW);
    digitalWrite(ledPin2,LOW);
    digitalWrite(ledPin3,LOW);
    digitalWrite(ledPin4,LOW);
  }
}

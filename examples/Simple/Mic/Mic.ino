/*
Example illustrates the noise level using the mic of your
Smartphone and when exceeds certain limit LED on pin 13 goes 
ON
*/

/*Include OneSheeld Library*/
#include <OneSheeld.h>


void setup () 
{
  /*Start UART communication on baudrate 115200*/
  OneSheeld.begin();
  /*Set pin 2 OUTPUT for the LED*/
  pinMode(2,OUTPUT);
}


void loop ()
{
  /*Always check the Noise level from your Smartphone mic*/
  if(Mic.getValue()>80)
  {
    /*LED on*/
    digitalWrite(2,HIGH);
  }
  else 
  {
    /*LED off*/
    digitalWrite(2,LOW);
  }
}

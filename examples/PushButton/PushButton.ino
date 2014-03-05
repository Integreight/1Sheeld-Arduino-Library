/*
Example illustrates the use of the Push button in 1Sheeld
*/

//including the OneSheeld Library 
#include <OneSheeld.h>

//reserving an integer varaiable to get the state of the button 
int state;

void setup()
{
  //Starting the Uart communication on baudrate 57600
  OneSheeld.begin();
  //set pin 13 as input
  pinMode(13,INPUT);
  //set pin A0 as output 
  pinMode(A0,OUTPUT);
}

void loop()
{
  //listen pin 13 and check out it's value and put it in state
  state=digitalRead(13);
  //if the button is pressed ignite the light 
  if(state==HIGH)
  {
    digitalWrite(A0,HIGH);
  }
  //if not pressed nothing is done 
  else
  {
    digitalWrite(A0,LOW);`
  }
}




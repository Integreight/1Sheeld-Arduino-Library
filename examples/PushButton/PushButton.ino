/*
Example illustrates the use of the Push button in 1Sheeld
*/

/*including the OneSheeld Library*/
#include <OneSheeld.h>

/*reserving an integer varaiable to get the state of the button*/
int state;

void setup()
{
  /*Starting the Uart communication on baudrate 57600*/
  OneSheeld.begin();
  /*set pin 13 as input*/
  pinMode(13,OUTPUT);
}

void loop()
{
  /*Always check if the PushButton is pressed*/
  if(PushButton.getValue()>0)
  {
    /*Set the Led to HIGH*/
    digitalWrite(13,HIGH);
  }
  else
  {
    /*Set the Led to LOW*/
    digitalWrite(13,LOW);
  }

}




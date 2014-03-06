/*
Example illustrates Light Sensor in the Smart Phones and when light fades 
turn on some LEDs so as to get some light in the night 
*/

//including the OneSheeld Library
#include <OneSheeld.h>

//reserve an integer type variable that will loop on all the pins to make it output
int i;
void setup ()
{
  //Starting the UART communication on baudrate 57600
  OneSheeld.begin();
  //set all pins as output by looping on them  
  for(i=2 ; i<14 ;i++)
  {
    pinMode(i,OUTPUT);
  }
}

void loop () 
{
  //always check out the light intensity and if it was down the limits turn on the LEDs
  if (LightSensor.getValue()<50)
  {
    for (i=2 ; i<14 ; i++)
    {
      digitalWrite(i,HIGH);
    }
  }
  else 
  {
    //Turn off the LEDs 
    for (i=2 ; i<14 ; i++)
    {
      digitalWrite(i,LOW);
    }
  }
}

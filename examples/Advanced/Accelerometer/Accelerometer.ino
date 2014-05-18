/*
Example illustrates grabbing your Smartphone Carefully! and Strike as if you are bowling
so you can turn on the led on pin 13 
*/

/*Inculde OneSheeld Library*/
#include <OneSheeld.h>

/*Accelerometer Values in 3D*/
float x;
float y;
float z;

/*Led on pin 13*/
int ledPin = 13 ;

void setup () 
{
  /*Start Communication*/
  OneSheeld.begin();
  /*Set pin ledPin OUTPUT*/
  pinMode(ledPin,OUTPUT);
}


void loop () 
{
  /*Always get the values of the Accelerometer in the 3 Dimensions (X-Y-Z)*/
  x=AccelerometerSensor.getX();
  y=AccelerometerSensor.getY();
  z=AccelerometerSensor.getZ();
  
  /*Check the Motion of the Smart phone when exceeded a limit turn the LED ON by calcuating the Magnitude
  of the 3D vectors*/
  if (sqrt((x*x)+(y*y)+(z*z))>31)
  {
    /*Turn on the LED */
    digitalWrite(ledPin,HIGH);
  }
  else
  {
    /*Turn off the LED*/
    digitalWrite(ledPin,LOW);
  }
}

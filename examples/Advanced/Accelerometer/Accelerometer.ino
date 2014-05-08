/*
Example illustrates the strike speed of the racket from tennis player using the Accelerometer 
Sensor in the Smart Phone which requires you to hold the Smart Phone carefully and strike to 
see how much your strike is effective
*/

/*Inculde OneSheeld Library*/
#include <OneSheeld.h>

/*Reserving Variables for the Accelerometer Values in 3D*/
float x;
float y;
float z;
/*Led on 13*/
int ledPin = 13 ;
void setup () 
{
  /*Start Communication*/
  OneSheeld.begin();
  /*Set pin 13 OUTPUT*/
  pinMode(ledPin,OUTPUT);
}


void loop () 
{
  /*Always get the values of the Accelerometer in 3D*/
  x=AccelerometerSensor.getX();
  y=AccelerometerSensor.getY();
  z=AccelerometerSensor.getZ();
  
  /*Check the Motion of the Smart phone when exceeded a limit ignite*/
  if (sqrt((x*x)+(y*y)+(z*z))>31)
  {
    /*Put on the LED */
    digitalWrite(ledPin,HIGH);
  }
  else
  {
    /*Put off the LED*/
    digitalWrite(ledPin,LOW);
  }
}

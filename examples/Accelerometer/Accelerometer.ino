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

void setup () 
{
  /*Start UART communication on Baud rate 57600*/
  OneSheeld.begin();
  /*Set pin 13 OUTPUT*/
  pinMode(13,OUTPUT);
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
    /*LED on*/
    digitalWrite(13,HIGH);
  }
  else
  {
    /*LED off*/
    digitalWrite(13,LOW);
  }
}

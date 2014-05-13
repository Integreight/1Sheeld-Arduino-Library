/*
Example illustrates the Accelerometer sensor and checking the acceleration 
in the 3 dimensions and igniting LED 13 when reaches the gravity acceleration
in X-Y-Z Axis
*/

/*Include OneSheeld library*/
#include <OneSheeld.h>

int ledPin = 13 ;

void setup ()
{
  /*Start communication*/
  OneSheeld.begin();
  /*Set LedPin as OUTPUT*/
  pinMode(ledPin,OUTPUT);
}

void loop ()
{
  /*Check X-Axis gravitational Acceleration*/
  if(AccelerometerSensor.getX()>8)
  {
    digitalWrite(ledPin,HIGH);
  }
  else
  {  
    digitalWrite(ledPin,LOW);
  }
  /*Check Y-Axis gravitational Acceleration*/
  if(AccelerometerSensor.getY()>8)
  {
    digitalWrite(ledPin,HIGH);
  }
  else
  {
    digitalWrite(ledPin,LOW);
  }
  /*Check Z-Axis gravitational Acceleration*/  
  if(AccelerometerSensor.getZ()>8)
  {
    digitalWrite(ledPin,HIGH);
  }
  else
  {
    digitalWrite(ledPin,LOW);
  }
}

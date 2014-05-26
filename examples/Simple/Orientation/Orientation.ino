/*
Example illustrates the Orientation of your SmartPhone and turning ON a LED when the
Orientation exceeds certain limits on 3 Dimensions
*/

/*Include OneSheeld Library*/
#include <OneSheeld.h>

/*LedPin on 13*/
int ledPin1 = 13 ;
/*LedPin on 12*/
int ledPin2 = 12 ;
/*LedPin on 11*/
int ledPin3 = 11 ;

void setup () 
{
  /*Start Communication*/
  OneSheeld.begin();
  /*Set the ledPin OUTPUT*/
  pinMode(ledPin1,OUTPUT);
  pinMode(ledPin2,OUTPUT);
  pinMode(ledPin3,OUTPUT);
}

void loop ()
{
  /*Check the X-Axis Orientation*/
  if(OrientationSensor.getX()>350)
  {
    digitalWrite(ledPin1,HIGH);
  }
  else
  {
    digitalWrite(ledPin1,LOW);
  }
  /*Check the Y-Axis Orientation*/
  if(OrientationSensor.getY()>170)
  {
    digitalWrite(ledPin2,HIGH);
  }
  else
  {
    digitalWrite(ledPin2,LOW);
  }
  /*Check the Z-Axis Orientation*/
  if(OrientationSensor.getZ()>80) 
  {
    digitalWrite(ledPin3,HIGH);
  }
  else
  {
    digitalWrite(ledPin3,LOW);
  }
  
}

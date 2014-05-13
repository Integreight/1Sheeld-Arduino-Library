/*
Example illustrates the Gyroscope shield and sensing its values on the Three directions
X/Y/Z-Axis 
*/

/*Including OneSheeld Library*/
#include <OneSheeld.h>



void setup ()
{
  /*Start communication*/
  OneSheeld.begin();
  /*Set some pins as OUTPUT*/
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
}


void loop () 
{
  /*Always get the values of the Gyroscope*/

  /*Check the X-Axis motion*/
  if(GyroscopeSensor.getX()>1)
  {
    digitalWrite(13,HIGH);
    digitalWrite(12,LOW);
    digitalWrite(11,LOW);
  }
  /*Check the Y-Axis motion*/
  else if(GyroscopeSensor.getY()>1)
  {
    digitalWrite(12,HIGH);
    digitalWrite(13,LOW);
    digitalWrite(11,LOW);
  } 
  /*Check the Z-Axis motion*/
  else if(GyroscopeSensor.getZ()>1)
  {
    digitalWrite(11,HIGH);
    digitalWrite(13,LOW);
    digitalWrite(12,LOW);
  }
}

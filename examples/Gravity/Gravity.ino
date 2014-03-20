/*
Example illustrates Gravity sensor on 3 Axis (X-Y-Z) and igniting LED when a certain 
Axis reach it's maximum gravity 
*/

/*Including OneSheeld Library*/
#include <OneSheeld.h>


void setup () 
{
  /*Start UART communication on baudrate 57600*/
  OneSheeld.begin();
  /*Set pin 13/12/11 as OUTPUT*/
  pinMode (13,OUTPUT);
  pinMode (12,OUTPUT);
  pinMode (11,OUTPUT); 
}


void loop () 
{
  /*Checking the Gravity on the X-Axis*/
  if (GravitySensor.getX()>=9)
  {
    /*Red LED ignite*/
    digitalWrite(13,HIGH);
    /*The second two LED are off*/
    digitalWrite(12,LOW);
    digitalWrite(11,LOW);    
  }
  
  /*Checking the Gravity on the Y-Axis*/
  else if (GravitySensor.getY()>=9)
  {
    /*Green LED ignite*/
    digitalWrite(12,HIGH);
    /*The second two LED are off*/
    digitalWrite(13,LOW);
    digitalWrite(11,LOW);    
  }
  
  /*Checking the Gravity on the Z-Axis*/
  else if (GravitySensor.getZ()>=9)
  {
    /*Yellow LED ignite*/
    digitalWrite(11,HIGH);
    /*The second two LED are off*/
    digitalWrite(13,LOW);
    digitalWrite(12,LOW);    
  }
  
}

/*
Example illustrates Gravity sensor on 3 Axis (X-Y-Z) and turning ON an LED when a certain 
Axis reaches its maximum gravity 
*/

/*Including OneSheeld Library*/
#include <OneSheeld.h>

/*Led on 13*/
int ledPin1 = 13;
/*Led on 12*/
int ledPin2 = 12;
/*Led on 11*/
int ledPin3 = 11;
void setup () 
{
  /*Start Communication*/
  OneSheeld.begin();
  /*Leds 1,2,3 OUTPUT*/
  pinMode (ledPin1,OUTPUT);
  pinMode (ledPin2,OUTPUT);
  pinMode (ledPin3,OUTPUT); 
}


void loop () 
{
  /*Checking the Gravity on the X-Axis*/
  if (GravitySensor.getX()>=9)
  {
    /*Red LED turned ON*/
    digitalWrite(ledPin1,HIGH);
    /*The other two LEDs are off*/
    digitalWrite(ledPin2,LOW);
    digitalWrite(ledPin3,LOW);    
  }
  
  /*Checking the Gravity on the Y-Axis*/
  if (GravitySensor.getY()>=9)
  {
    /*Green LED turned ON*/
    digitalWrite(ledPin2,HIGH);
    /*The other two LEDs are off*/
    digitalWrite(ledPin1,LOW);
    digitalWrite(ledPin3,LOW);    
  }
  
  /*Checking the Gravity on the Z-Axis*/
  if (GravitySensor.getZ()>=9)
  {
    /*Yellow LED turned ON*/
    digitalWrite(ledPin3,HIGH);
    /*The other two LEDs are off*/
    digitalWrite(ledPin1,LOW);
    digitalWrite(ledPin2,LOW);    
  }
  
}

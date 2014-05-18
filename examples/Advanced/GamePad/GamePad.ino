/*
Example illustrates Running the Warrior Kit (2Wheel Car)using the Gamepad 
in Onesheeld
Notification: Motor shield of arduino's has different configuration 
than SEED's Motor shield
*/

/*Include OneSheeld Library*/
#include <OneSheeld.h>

/*Led on pin 7*/
int ledPin = 7 ;
/*Pin configuration of the SEED Motor Shield*/
int motorAPin1 = 8;
int motorAPin2 = 11;
int motorBPin1 = 12;
int motorBPin2 = 13;
int motorASpeedPin = 9;
int motorBSpeedPin = 10;


void setup () 
{
  /*Start the Communication*/
  OneSheeld.begin();
  /*Set the ledPin as OUTPUT*/
  pinMode(ledPin,OUTPUT);
  /*Motor Shield Initialization*/  
  pinMode(motorAPin1,OUTPUT);  //IN1 of motor A
  pinMode(motorAPin2,OUTPUT); //IN2 of motor A
  pinMode(motorBPin1,OUTPUT);  //IN3 of motor B
  pinMode(motorBPin2,OUTPUT);  //IN4 of motor B
  pinMode(motorASpeedPin,OUTPUT);  //speed of motor A
  pinMode(motorBSpeedPin,OUTPUT); //speed of Motor B
}



void loop () 
{
  
  /*Turn on the LED when Red Button is pressed*/
  if(GamePad.isRedPressed())
  {
    /*Turn on the Led*/
    digitalWrite(ledPin,HIGH);
  }
  else 
  {
    /*Turn off the Led*/
    digitalWrite(ledPin,LOW);
  }
  /*GamePad Section*/
  if(GamePad.isUpPressed())
  {
    analogWrite(motorASpeedPin, 255);   
    analogWrite(motorBSpeedPin, 255);
    digitalWrite(motorAPin1,LOW);
    digitalWrite(motorAPin2, HIGH);
    digitalWrite(motorBPin1,LOW);
    digitalWrite(motorBPin2, HIGH);
  }
  else if (GamePad.isDownPressed())
  {
    analogWrite(motorASpeedPin, 255);   
    analogWrite(motorBSpeedPin, 255);
    digitalWrite(motorAPin1,HIGH);
    digitalWrite(motorAPin2, LOW);
    digitalWrite(motorBPin1,HIGH);
    digitalWrite(motorBPin2, LOW);
    
  }
  else if (GamePad.isRightPressed())
  {
    analogWrite(motorASpeedPin, 255);   
    analogWrite(motorBSpeedPin, 255);
    digitalWrite(motorAPin1,LOW);
    digitalWrite(motorAPin2,HIGH);
    digitalWrite(motorBPin1,HIGH);
    digitalWrite(motorBPin2,LOW);
  }
  else if(GamePad.isLeftPressed())
  {
    analogWrite(motorASpeedPin, 255);   
    analogWrite(motorBSpeedPin, 255);
    digitalWrite(motorAPin1,HIGH);
    digitalWrite(motorAPin2, LOW);
    digitalWrite(motorBPin1,LOW);
    digitalWrite(motorBPin2, HIGH);
  }
  else 
  {
    analogWrite(motorASpeedPin, 0);   
    analogWrite(motorBSpeedPin, 0); 
    digitalWrite(ledPin,LOW); 
  }
  
}

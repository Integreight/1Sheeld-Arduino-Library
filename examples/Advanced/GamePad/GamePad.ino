/*

Gamepad Shield Example

This example shows an application on 1Sheeld's gamepad shield.

By using this example, you can control a 2-wheel car (like the
one in our warrior kit) using the gamepad in our app along with
Seeedstudio's motor shield.

PS: Arduino's motor shield has different configuration.

OPTIONAL:
To reduce the library compiled size and limit its memory usage, you
can specify which shields you want to include in your sketch by
defining CUSTOM_SETTINGS and the shields respective INCLUDE_ define. 

*/

#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_SHIELD

/* Include 1Sheeld library. */
#include <OneSheeld.h>

/* A name for the LED on pin 7. */
int ledPin = 7 ;

/* Pin configuration of the Seeedstudio's motor shield. */
int motorAPin1 = 8;
int motorAPin2 = 11;
int motorBPin1 = 12;
int motorBPin2 = 13;
int motorASpeedPin = 9;
int motorBSpeedPin = 10;

void setup() 
{
  /* Start communication. */
  OneSheeld.begin();
  /* Set the LED pin as output. */
  pinMode(ledPin,OUTPUT);
  /* Seeedstudio's motor shield initialization. */  
  pinMode(motorAPin1,OUTPUT);     // IN1 of motor A
  pinMode(motorAPin2,OUTPUT);     // IN2 of motor A
  pinMode(motorBPin1,OUTPUT);     // IN3 of motor B
  pinMode(motorBPin2,OUTPUT);     // IN4 of motor B
  pinMode(motorASpeedPin,OUTPUT); // Speed of motor A
  pinMode(motorBSpeedPin,OUTPUT); // Speed of Motor B
}

void loop() 
{
  
  /* Turn on the LED when the red button is pressed. */
  if(GamePad.isRedPressed())
  {
    /* Turn on the LED. */
    digitalWrite(ledPin,HIGH);
  }
  else 
  {
    /* Turn off the LED. */
    digitalWrite(ledPin,LOW);
  }

  /* If up is pressed, move the car forward. */
  if(GamePad.isUpPressed())
  {
    analogWrite(motorASpeedPin, 255);   
    analogWrite(motorBSpeedPin, 255);
    digitalWrite(motorAPin1,LOW);
    digitalWrite(motorAPin2, HIGH);
    digitalWrite(motorBPin1,LOW);
    digitalWrite(motorBPin2, HIGH);
  }
  /* If down is pressed, move the car backwards. */
  else if (GamePad.isDownPressed())
  {
    analogWrite(motorASpeedPin, 255);   
    analogWrite(motorBSpeedPin, 255);
    digitalWrite(motorAPin1,HIGH);
    digitalWrite(motorAPin2, LOW);
    digitalWrite(motorBPin1,HIGH);
    digitalWrite(motorBPin2, LOW);
    
  }
  /* If right is pressed, turn the car to the right. */
  else if (GamePad.isRightPressed())
  {
    analogWrite(motorASpeedPin, 255);   
    analogWrite(motorBSpeedPin, 255);
    digitalWrite(motorAPin1,LOW);
    digitalWrite(motorAPin2,HIGH);
    digitalWrite(motorBPin1,HIGH);
    digitalWrite(motorBPin2,LOW);
  }
    /* If left is pressed, turn the car to the left. */
  else if(GamePad.isLeftPressed())
  {
    analogWrite(motorASpeedPin, 255);   
    analogWrite(motorBSpeedPin, 255);
    digitalWrite(motorAPin1,HIGH);
    digitalWrite(motorAPin2, LOW);
    digitalWrite(motorBPin1,LOW);
    digitalWrite(motorBPin2, HIGH);
  }
  /* If nothing is pressed stop all motors. */
  else 
  {
    analogWrite(motorASpeedPin, 0);   
    analogWrite(motorBSpeedPin, 0); 
    digitalWrite(ledPin,LOW); 
  }
  
}

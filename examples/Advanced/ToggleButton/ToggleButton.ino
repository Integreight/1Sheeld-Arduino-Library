/*
Example illustrates the Toggle button controls a Seven Segment (Hardware) to start count from 0-->9
*/

/* Include 1Sheeld library. */
#include <OneSheeld.h>

/* Seven segment pins. */
int pin1 = 2;
int pin2 = 3;
int pin3 = 4;
int pin4 = 5;
int pin5 = 6;
int pin6 = 7;
int pin7 = 8;
int pin8 = 9;

/* A name for the button on pin 12. */
int buttonPin = 12;
/* Define a two dimensional array for the values of the numbers from 0 to 9. */
byte sevenSegmentDigits[10][7] = { { 1,1,1,1,1,1,0 },  // = 0
                                   { 0,1,1,0,0,0,0 },  // = 1
                                   { 1,1,0,1,1,0,1 },  // = 2
                                   { 1,1,1,1,0,0,1 },  // = 3
                                   { 0,1,1,0,0,1,1 },  // = 4
                                   { 1,0,1,1,0,1,1 },  // = 5
                                   { 1,0,1,1,1,1,1 },  // = 6
                                   { 1,1,1,0,0,0,0 },  // = 7
                                   { 1,1,1,1,1,1,1 },  // = 8
                                   { 1,1,1,1,0,1,1 }   // = 9
                               };

void setup() 
{
  /* Start communication. */
  OneSheeld.begin();
  /* Set the button pin as input. */
  pinMode(buttonPin,INPUT);
  /* Set 7 pins of Arduino as output. (from 2 till 8) */
  pinMode(pin1,OUTPUT);
  pinMode(pin2,OUTPUT);
  pinMode(pin3,OUTPUT);
  pinMode(pin4,OUTPUT);
  pinMode(pin5,OUTPUT);
  pinMode(pin6,OUTPUT);
  pinMode(pin7,OUTPUT);
  pinMode(pin8,OUTPUT);
}

void loop() 
{
  if (digitalRead(buttonPin) == HIGH)
  { 
      for (int count = 0 ; count < 10 ; count++)
      {
        delay(1000);
        int pin = 2;
        /* Output the digit to the seven segment. */
        for (int digit = 0 ; digit < 7; digit++)
           {  
              digitalWrite(pin,sevenSegmentDigits[count][digit]);
              pin++;
           } 
      }
  }
}

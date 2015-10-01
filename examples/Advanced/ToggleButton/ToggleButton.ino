/*

Toggle Button Shield Example

This example shows an application on 1Sheeld's toggle button shield.

By using this example, you can display the numbers from
0 till 9 on the hardware seven segment every time you press
the button on pin 12.

PS: This example doesn't require you to include our Arduino
library. You can connect the toggle button directly from the
shield screen on our app to any Arduino pin you want.

OPTIONAL:
To reduce the library compiled size and limit its memory usage, you
can specify which shields you want to include in your sketch by
defining CUSTOM_SETTINGS and the shields respective INCLUDE_ define. 

*/


/* Seven segment pins. */
int segmentA = 2;
int segmentB = 3;
int segmentC = 4;
int segmentD = 5;
int segmentE = 6;
int segmentF = 7;
int segmentG = 8;

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
  /* Set the button pin as input. */
  pinMode(buttonPin,INPUT);
  /* Set 7 pins of Arduino as output. (from 2 till 8) */
  pinMode(segmentA,OUTPUT);
  pinMode(segmentB,OUTPUT);
  pinMode(segmentC,OUTPUT);
  pinMode(segmentD,OUTPUT);
  pinMode(segmentE,OUTPUT);
  pinMode(segmentF,OUTPUT);
  pinMode(segmentG,OUTPUT);
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

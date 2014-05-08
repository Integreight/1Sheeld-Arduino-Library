/*
Example illustrates the Toggle button controls a Seven Segment (Hardware) to start count from 0-->9
*/

/*Including OneSheeld Library*/
#include <OneSheeld.h>

/*Seven Segment pins*/
int pin1 = 2;
int pin2 = 3;
int pin3 = 4;
int pin4 = 5;
int pin5 = 6;
int pin6 = 7;
int pin7 = 8;
int pin8 = 9;
/*Button on 12*/
int buttonPin = 12;
/*Reserving a two dimensional array for the values of counting 0-->9*/
byte seven_seg_digits[10][7] = { { 1,1,1,1,1,1,0 },  // = 0
                                 { 0,1,1,0,0,0,0 },  // = 1
                                 { 1,1,0,1,1,0,1 },  // = 2
                                 { 1,1,1,1,0,0,1 },  // = 3
                                 { 0,1,1,0,0,1,1 },  // = 4
                                 { 1,0,1,1,0,1,1 },  // = 5
                                 { 1,0,1,1,1,1,1 },  // = 6
                                 { 1,1,1,0,0,0,0 },  // = 7
                                 { 1,1,1,1,1,1,1 },  // = 8
                                 { 1,1,1,0,0,1,1 }   // = 9
                               };

void setup () 
{
  /*Start Communication*/
  OneSheeld.begin();
  /*buttonPin as INPUT*/
  pinMode(buttonPin,INPUT);
  /*Set 7 pins from 2-->8 as OUTPUT*/
  pinMode(pin1,OUTPUT);
  pinMode(pin2,OUTPUT);
  pinMode(pin3,OUTPUT);
  pinMode(pin4,OUTPUT);
  pinMode(pin5,OUTPUT);
  pinMode(pin6,OUTPUT);
  pinMode(pin7,OUTPUT);
  pinMode(pin8,OUTPUT);
}

void loop () 
{
  if (digitalRead(buttonPin) == HIGH)
  {
       
      for (byte count=0; count<10;++count)
      {
        delay(1000);
        byte pin = 2;
        for (byte digit = 0; digit<7;digit++)
           {  
              digitalWrite(pin,seven_seg_digits[count][digit]);
              pin++;
           } 
      }
     delay(4000); 
  }
}

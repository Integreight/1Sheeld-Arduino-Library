/*
Example illustrates the Toggle button controls a Seven Segment to start count from 0-->9
*/

/*Including OneSheeld Library*/
#include <OneSheeld.h>

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
  /*Start UART communication on baudrate 57600*/
  OneSheeld.begin();
  /*Set pin 13 as INPUT*/
  pinMode(13,INPUT);
  /*Set 7 pins from 2-->8 as OUTPUT*/
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
}

void loop () 
{
  if (digitalRead(13)==HIGH)
  {
       
      for (byte count=0; count<10;++count)
      {
        delay(1000);
        byte pin =2;
        for (byte digit = 0; digit<7;digit++)
           {  
              digitalWrite(pin,seven_seg_digits[count][digit]);
              pin++;
           } 
      }
     delay(4000); 
  }
}

/*
Example illustrates the Seven Segment display in 1Sheeld making 
displaying numbers from 0 up to 9
*/

//including the Library OneSheeld 
#include <OneSheeld.h>

//reserving a variable to get the state of the push button 
int state;
//reserve a varaiable that holds the numbers from 0-->9 and declaring it first by zero
int number=0;

void setup()
{
  //Starting the UART communication on baudrate 57600
  OneSheeld.begin();
  //set pin 13 as INPUT
  pinMode(13,INPUT);
}


void loop()
{
  //always check the state of pin 13
  state=digitalRead(13);
  //if it is high display numbers on the Seven Segment 
  if(state==HIGH)
 {
   //Display the number in Seven Segment
   SevenSegment.setNumber(number);
   //increment the number so as if button is pressed the next number is displayed 
   number++;
   //Check the number if it is bigger than 9 return the number to zero
   if (number>9)  number=0;
 }
   
}

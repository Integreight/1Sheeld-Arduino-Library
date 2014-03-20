/*
Example illustrates Seven Segment incrementation from 0--->9 each 
time a button pushed 
*/

/*Include OneSheeld Library*/
#include <OneSheeld.h>

/*Reserve a variable for the incrementation value and initialize it by zero*/
int number=0;

void setup () 
{
  /*Start UART communication on baudrate 57600*/
  OneSheeld.begin();
  /*Set pin 13 as INPUT*/
  pinMode(13,INPUT);
}


void loop () 
{
  if (digitalRead(13)==HIGH)
  {
    /*Send the number to the Seven Segment*/
    SevenSegment.setNumber(number);
    delay(1000);
    /*Increment the number*/
    number++;
    /*Check the number if it reaches to 9 put it again to zero*/
    if(number==10)
    {
      /*Initialize the number back agian by zero*/
      number=0;
    }
  }
}

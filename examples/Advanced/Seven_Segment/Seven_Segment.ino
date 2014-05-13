/*
Example illustrates Seven Segment incrementation from 0--->9 each 
time a button pushed 
*/

/*Include OneSheeld Library*/
#include <OneSheeld.h>

/*Reserve a variable for the incrementation value and initialize it by zero*/
int number=0;
/*Button on 12*/
int ledPin = 12;

void setup () 
{
  /*Start communication*/
  OneSheeld.begin();
  /*ButtonPin as INPUT*/
  pinMode(buttonPin,INPUT);
}


void loop () 
{
  if (digitalRead(buttonPin) == HIGH)
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

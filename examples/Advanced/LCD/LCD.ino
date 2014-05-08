/*
Example illustrates the Liquid Crystal Display Shield
*/

/*including the OneSheeld Library*/ 
#include <OneSheeld.h>

/*button on 12*/
int buttonPin = 12;

void setup () 
{
  /*Starting the UART communication on baudrate 57600*/
  OneSheeld.begin();
  /*buttonPin INPUT*/
  pinMode(buttonPin,INPUT);  
}


void loop ()
{
  /*always Check the button if it is it's pressed display texts on LCD*/
  if(digitalRead(buttonPin) == HIGH)
  {
   /*begin the LCD cursor at the first row and first column*/
   LCD.begin(1,1);
   /*blink the cursor and for 10 seconds*/
   LCD.blink();
   delay(10000);
   /*stop blinking*/
   LCD.noBlink();
   /*write characters on LCD*/
   LCD.write('A');
   LCD.write('B');
   LCD.write('C');
   /*clear the LCD*/ 
   LCD.clear();
   /*print Hello World*/
   LCD.print("Hello World");
   /*set the cursor to begin writing from the second row and first column*/
   LCD.setCursor(2,1);
   /*print This is OneSheeld*/ 
   LCD.print("This is OneSheeld");
   /*wait about 20 seconds*/  
   delay(20000);
   /*print Bye Bye*/
   LCD.print("BYE BYE");
   /*turn off the display*/
   LCD.noDisplay();
    
  }
  
  
   
}

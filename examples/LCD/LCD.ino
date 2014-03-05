/*
Example illustrates the Liquid Crystal Display Shield
*/

//including the OneSheeld Library 
#include <OneSheeld.h>

//reserving an array for the custom character 
char  character[8]={0x00,0x0A,0x0A,0x0A,0x00,0x01,0x0E,0x00};  

void setup () 
{
  //Starting the UART communication on baudrate 57600
  OneSheeld.begin();
  //set pin 13 as an in put 
  pinMode(13,INPUT);  
}


void loop ()
{
  //always Check pin 13 if it is high (5V) display texts on LCD
  if(digitalRead(13)==HIGH)
  {
   //begin the LCD cursor at the first row and first column
   LCD.begin(1,1);
   //blink the cursor and for 10 seconds
   LCD.blink();
   delay(10000);
   //stop blinking
   LCD.noBlink();
   //write characters on LCD 
   LCD.write('A');
   LCD.write('B');
   LCD.write('C');
   //clear the LCD 
   LCD.clear();
   //print Hello World 
   LCD.print("Hello World");
   //set the cursor to begin writing from the second row and first column 
   LCD.setCursor(2,1);
   //print This is OneSheeld 
   LCD.print("This is OneSheeld");
   //print a custom character "a Smiley face" 
   LCD.createChar(character);
   //wait about 20 seconds  
   delay(20000);
   //print Bye Bye
   LCD.print("BYE BYE");
   //turn off the display
   LCD.noDisplay();
    
  }
  
  
   
}

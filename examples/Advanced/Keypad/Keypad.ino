/*
Example illustrates the Passphrase from the Keypad and if it's correct, 
blink LED twice if it's wrong, LED will not blink! 
DISCLAIMER: This Example is for FUN not for REAL SECURITY SYSTEMS and 
in case used in real security system it will be under your responsibility 
*/

/*Including OneSheeld Library */
#include <OneSheeld.h>

/*Reserve an iterator*/ 
int iterations=0;
/*Led on 13*/
int ledPin = 13;

void setup () 
{
  /*Start UART communication on baud rate 57600*/
  OneSheeld.begin();
  /*ledPin OUTPUT*/
  pinMode(ledPin,OUTPUT);
}

void loop()
{
  /*Check if One is pressed and if pressed, iterate one time*/ 
  if(iterations==0 && isOnePressed())
  {
     iterations++;
  }
  /*Check if Two is pressed and if pressed, iterate one time*/ 
  else if (iterations==1 && isTwoPressed())
  {
     iterations++;
  }
  /*Check if Three is pressed and if pressed, iterate one time*/ 
  else if (iterations==2 && isThreePressed())
  {
     iterations++;
  }
  /*Check if Four is pressed and if pressed, iterate one time*/
  else if(iterations==3 && isFourPressed())
  {
     iterations++;
  }
  /*Check if any other button is pressed, reset iterations*/
  else if(isOtherButtonPressed())
  {
    iterations=0;
  }
     
     /*Check if the Number of iterations = 4, blink LED*/
     if(iterations==4)
     {    
          digitalWrite(ledPin,HIGH);
          delay(500);
          digitalWrite(ledPin,LOW);
          /*Reset the iterator*/
          iterations=0;
     }
}
 
/*Functions to return True or False if a Certain Button Pressed*/
/*Checking on button One*/
boolean isOnePressed(){
  return Keypad.isRowPressed(0)&&Keypad.isColumnPressed(0);
}
/*Checking on button Two*/
boolean isTwoPressed(){
  return Keypad.isRowPressed(0)&&Keypad.isColumnPressed(1);
}
/*Checking on button Three*/
boolean isThreePressed(){
  return Keypad.isRowPressed(0)&&Keypad.isColumnPressed(2);
}
/*Checking on button Four*/
boolean isFourPressed(){
  return Keypad.isRowPressed(1)&&Keypad.isColumnPressed(0);
}
/*Checking if Button pressed other than one or two or three or four*/
boolean isOtherButtonPressed(){
  return ((Keypad.isAnyColumnPressed()||Keypad.isAnyColumnPressed())&&!isOnePressed()&&!isTwoPressed()&&!isThreePressed()&&!isFourPressed());
}


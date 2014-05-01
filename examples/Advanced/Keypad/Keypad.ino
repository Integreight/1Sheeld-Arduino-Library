/*
Example illustrates the Passphrase from the Keypad and if it was a correct one 
blink the Led twice if it was wrong led will not blink 
DISCLAMER: This Example is for the FUN use not for REAL SECURITY SYSTEMS and 
in case used in real security system it will be under your responsibility 
*/

/*Including OneSheeld Library */
#include <OneSheeld.h>

/*Reserve an iterator*/ 
int iterations=0;

void setup () 
{
  /*Start UART communication on baud rate 57600*/
  OneSheeld.begin();
  /*Let pin 13 OUTPUT*/
  pinMode(13,OUTPUT);
}

void loop()
{
  /*Check if One is pressed and if pressed iterate one time*/ 
  if(iterations==0 && isOnePressed())
  {
     iterations++;
  }
  /*Check if Two is pressed and if pressed iterate one time*/ 
  else if (iterations==1 && isTwoPressed())
  {
     iterations++;
  }
  /*Check if Three is pressed and if pressed iterate one time*/ 
  else if (iterations==2 && isThreePressed())
  {
     iterations++;
  }
  /*Check if Four is pressed and if pressed iterate one time*/
  else if(iterations==3 && isFourPressed())
  {
     iterations++;
  }
  /*Check if Another button pressed reset iterations*/
  else if(isOtherButtonPressed())
  {
    iterations=0;
  }
     
     /*Check if the Number of iterations equal Four blink LED*/
     if(iterations==4)
     {    
          digitalWrite(13,HIGH);
          delay(500);
          digitalWrite(13,LOW);
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


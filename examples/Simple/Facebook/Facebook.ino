/*
Example illustrates updating status on Facebook by pressing a button 
*/

/*Including OneSheeld Library*/
#include <OneSheeld.h>

/*Variable for last state of the button*/
boolean lastState = LOW;
/*Button on pin 12*/
int buttonPin = 12;
/*Led on pin 13*/
int ledPin = 13;

void setup () 
{
  /*Start Communication*/
  OneSheeld.begin();
  /*Set buttonPin as INPUT*/
  pinMode(buttonPin,INPUT);
  /*Set ledPin as OUTPUT*/
  pinMode(ledPin,OUTPUT);
}

void loop ()
{
  boolean buttonState = debounce(lastState);
  /*Always check the button state*/
  if(lastState == LOW && buttonState == HIGH)
  {
    /*Twitter also can be used instead of Facebook*/
    /*Update your status on Facebbok*/
    Facebook.updateStatus("Home Sweet Home");
    /*Turn on the Led*/
    digitalWrite(ledPin,HIGH);
    delay(200);
  }
  else
  {
    digitalWrite(ledPin,LOW);
  }
  lastState = buttonState;
}

/*This Function prevent the hardware pushButton from bouncing*/ 
boolean debounce (boolean lastState)
{
  boolean currentState = digitalRead(buttonPin);
  
  if(currentState != lastState)
  {
    delay(10);
    currentState = digitalRead(buttonPin);
  }
  
  return currentState;
}

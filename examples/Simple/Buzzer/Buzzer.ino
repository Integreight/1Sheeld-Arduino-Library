/*
Example illustrates buzzing each time you press the button 
*/

/*Including OneSheeld Library*/
#include <OneSheeld.h>

boolean lastState = LOW;
int buttonPin = 12;
int ledPin = 13;
void setup () 
{
  /*Start Communication*/
  OneSheeld.begin();
  /*Let pin 13 as INPUT*/
  pinMode(buttonPin,INPUT);
  pinMode(ledPin,OUTPUT);
}
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

void loop ()
{
  boolean buttonState = debounce(lastState);
  /*Always check pin 13*/
  if(lastState == LOW && buttonState == HIGH)
  {
    /*Buzz*/
    Buzzer.buzzOn();
    digitalWrite(ledPin,HIGH);
    delay(200);
  }
  else
  {
    Buzzer.buzzOff();
    digitalWrite(ledPin,LOW);
  }
  lastState = buttonState;
}

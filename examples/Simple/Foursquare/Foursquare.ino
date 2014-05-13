/*
Example illustrates cheking in using Foursquare by pressing a button 
*/

/*Including OneSheeld Library*/
#include <OneSheeld.h>

boolean lastState = LOW;
int buttonPin = 12;
int ledPin = 13;
void setup () 
{
  /*Start UART communication on baudrate 57600*/
  OneSheeld.begin();
  /*Let pin 13 as INPUT*/
  pinMode(buttonPin,INPUT);
  pinMode(ledPin,OUTPUT);
}
/*solve bouncing issue to be sure the state is read once and right*/
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
    /*Checking in at My Work :INTEGRIEGHT*/
    Foursquare.checkIn("511759f2e4b0b0ae6ed91067","Back To Work");
    digitalWrite(ledPin,HIGH);
    delay(200);
  }
  else
  {
    digitalWrite(ledPin,LOW);
  }
  lastState = buttonState;
}

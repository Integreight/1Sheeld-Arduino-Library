/*
Example illustrates updating status on Facebook by pressing a button when you get back Home
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
    /*Twitter also can be used instead of Facebook*/
    /*Update your status on Facebbok*/
    Twitter.updateStatus("Home Sweet Home");
    digitalWrite(ledPin,HIGH);
    delay(200);
  }
  else
  {
    digitalWrite(ledPin,LOW);
  }
  lastState = buttonState;
}
/*
Example illustrates taking pictures each time you press the pushbutton (hardware)
*/

/*Include OneSheeld Library*/
#include <OneSheeld.h>

/*Variable to take the lastState of the button*/
boolean lastState = LOW ;
/*Button pin on OneSheeld*/
int buttonPin = 12 ;
/*Led pin on OneSheeld*/
int ledPin = 13;

void setup ()
{
  /*Start UART communication on baudrate 115200*/
  OneSheeld.begin();
  /*Set the buttonPin as INPUT*/
  pinMode(buttonPin,INPUT);
  /*Set the ledPin as OUTPUT*/
  pinMode(ledPin,OUTPUT);
  /*Set the Flash in the Camera*/
  Camera.setFlash(ON);
}
/*Debouncing Function for the pushButton problem*/
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
    /*Checking the state of the button*/
    boolean buttonState = debounce(lastState);
    /*if the State of the button was low and the became high
    the pushbutton is pressed*/
    if(lastState == LOW && buttonState == HIGH)
    {
      /*Take the Picture*/
      Camera.rearCapture();
      /*Ignite the LED*/
      digitalWrite(ledPin,HIGH);
      delay(300);
    }
    else
    {
      /*Put off the Led*/
      digitalWrite(ledPin,LOW);
    }
    
}

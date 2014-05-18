/*
Example illustrates taking pictures each time you press the pushbutton (hardware)
*/

/*Include OneSheeld Library*/
#include <OneSheeld.h>

/*Variable for last state of the button*/
boolean lastState = LOW ;
/*Button on pin 12*/
int buttonPin = 12 ;
/*Led on pin 13*/
int ledPin = 13;

void setup ()
{
  /*Start communication*/
  OneSheeld.begin();
  /*Set the buttonPin as INPUT*/
  pinMode(buttonPin,INPUT);
  /*Set the ledPin as OUTPUT*/
  pinMode(ledPin,OUTPUT);
}

void loop ()
{
    /*Checking the state of the button*/
    boolean buttonState = debounce(lastState);

    if(lastState == LOW && buttonState == HIGH)
    {
      /*Set the Flash in the Camera*/
      Camera.setFlash(ON);
      /*Take the Picture*/
      Camera.rearCapture();
      /*Turn on the LED*/
      digitalWrite(ledPin,HIGH);
      delay(1000);
    }
    else
    {
      /*Turn off the Led*/
      digitalWrite(ledPin,LOW);
    }
    
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

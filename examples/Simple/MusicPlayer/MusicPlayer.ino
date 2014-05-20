/*
Example illustrates putting the MusicPlayer On/Pause when a Button pressed
*/


/*Include OneSheeld Library*/
#include <OneSheeld.h>

/*Variable for last state of the button*/
boolean lastState = LOW;
/*Button on pin 12*/
int buttonPin = 12;
boolean musicPlayed = false;


void setup () 
{
  /*Start Communication*/
  OneSheeld.begin();
  pinMode(13,OUTPUT);
  
}

void loop ()
{
  boolean buttonState = debounce(lastState);
  /*Always check the button state*/
  if(lastState == LOW && buttonState == HIGH)
  { 
     if(musicPlayed == false)
     {
       MusicPlayer.play();
       musicPlayed =true;
       digitalWrite(13,HIGH);
     }   
     else
     {
       MusicPlayer.pause();
       musicPlayed = false;
       digitalWrite(13,LOW);
     }
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

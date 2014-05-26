/*
Example illustrates putting the MusicPlayer On/Pause when a Button pressed using 
two Hardware pushButtons
*/


/*Include OneSheeld Library*/
#include <OneSheeld.h>


/*Button on pin 12*/
int buttonPin1 = 12;
/*Button on pin 11*/
int buttonPin2 = 11;
/*Led on pin 13*/
int ledPin = 13;


void setup () 
{
  /*Start Communication*/
  OneSheeld.begin();
  /*Set ledPin as OUTPUT*/
  pinMode(ledPin,OUTPUT);
  /*Set buttonPin1 and buttonPin2 as INPUT*/
  pinMode(buttonPin1,INPUT);
  pinMode(buttonPin2,INPUT);
  
}

void loop ()
{

  /*Always check the buttonPin1 state*/
  if(digitalRead(buttonPin1)==HIGH)
  { 
       /*Turn LED On*/
       digitalWrite(ledPin,HIGH);
       /*Trun Music On*/
       MusicPlayer.play();
  }
  /*Always check the buttonPin2 state*/
  if(digitalRead(buttonPin2)==HIGH)
  { 
      /*Turn LED Off*/
      digitalWrite(ledPin,LOW);
      /*Turn Music Off*/
      MusicPlayer.pause();
      
  }
}

/*
Example illustrates pressing the Button to call your Friend
*/

/*Include OneSheeld Library*/
#include <OneSheeld.h>


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
  /*Always check the button state*/
  if(digitalRead(buttonPin)==HIGH)
  {
      /*Turn On the LED*/
      digitalWrite(ledPin,HIGH);
      /*Call my friend*/
      Phone.call("01119611432");
      /*Delay for not sending excessive Calls*/
      delay(300);
  }

  /*Turn Off the LED*/
  digitalWrite(ledPin,LOW);
}

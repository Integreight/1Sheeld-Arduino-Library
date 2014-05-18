/*
Example illustrates Rolling the Smartphone three times 
and send me a notification 
*/

/*Include OneSheeld Library*/
#include <OneSheeld.h>

/*Reserve a counter*/
int counter = 0 ;
/*Reserve a boolean*/
boolean Rolled = true;
/*Led on pin 13*/
int ledPin = 13;
void setup () 
{
  /*Start Communication*/
  OneSheeld.begin();
  /*Set ledPin as OUTPUT*/
  pinMode(ledPin,OUTPUT);
}


void loop () 
{
  /*Check the Smartphone if rolled on its X-Axis*/
  if(GravitySensor.getX()>9)
  {
    /*Check if rolled*/
    if(Rolled == true)
    {
      /*Increment the counter*/
      counter ++ ;
      /*Reset the boolean*/
      Rolled = false;  
    }
  }
  else 
  {
    /*Set the boolean*/
    Rolled =true;
  }
  /*Check if Rolled 3 times*/
  if (counter == 3)
  {
    /*Send me a notification*/
    Notification.notifyPhone("SmartPhone Rolled Three times");
    /*Turn On the LED*/
    digitalWrite(ledPin,HIGH);
    /*Wait half a second*/
    delay(500);
    /*Reset the Counter*/
    counter =0;
  }
  else
  {
    /*Turn Off the LED*/
    digitalWrite(ledPin,LOW);
  }
  
  
}

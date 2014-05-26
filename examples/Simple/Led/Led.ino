/*
Example illustrates Blinking the LED in 1Sheeld Application 
*/

/*Include OneSheeld Library*/
#include <OneSheeld.h>



void setup ()
{
  /*Start Communication*/
  OneSheeld.begin();
}

void loop () 
{
  /*Turn On the LED*/
  LED.setHigh();
  delay(1000);
  /*Turn Off the LED*/
  LED.setLow();
  delay(1000);
}

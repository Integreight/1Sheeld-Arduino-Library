/*
Example illustrates the Slider shield to control the frequency of the Piezo Speaker using 
the PWM values comming from the application 
*/

/*Include OneSheeld Library*/
#include <OneSheeld.h>

/*Reserve a value for the Slider*/
byte value;
void setup () 
{
  /*Start Communication*/
  OneSheeld.begin();
  /*Set pin 11 OUTPUT for PWM*/
  pinMode(11,OUTPUT);
}

void loop () 
{
  /*Always get the Values of the Slider and output it to pin 11*/
  value=Slider.getValue();
  analogWrite(11,value);
}

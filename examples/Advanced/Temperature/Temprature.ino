/*
Example illustrates Sensing the temperature of 
a room and Buzzing if the temperature exceeds a 
certain value
*/

/*Include OneSheeld Library*/
#include <OneSheeld.h>



void setup () 
{
   
  /*Start Communication*/
   OneSheeld.begin();
   
}

void loop()
{
    /*Buzz if the Temperature exceeds 20 degrees in Celsuis*/ 
    if (Temperature.getValue()>=20)
    {
      /*Buzzing*/
      Buzzer.buzzOn();
      /*Delay 10 seconds*/
      delay(10000);
      /*Stop Buzzing*/  
      Buzzer.buzzOff();
    }
    
}




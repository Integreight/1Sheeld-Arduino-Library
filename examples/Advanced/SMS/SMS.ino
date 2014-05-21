/*
Example illustrates sending SMS to my phone to notify me that the Temperature in my home 
increased and exceeded a certain limit 
*/

/*Including OneSheeld Library*/
#include <OneSheeld.h>

/*Reserve a variable for sending only one time*/
boolean messageSent = false;

void setup () 
{
 /*Start communication*/
 OneSheeld.begin(); 
}


void loop () 
{
  /*Always check the Temperature in the House*/
  if (TemperatureSensor.getValue()>30)
  {
    /*Check that the message sent only once and not annoy you by always sending in loop*/
    if(messageSent== false)
    {   
        /*Send me the Message*/ 
        SMS.send("+01286077028","Room Temperature is Bigger than 30 Degree");
        /*Reset the variable with false as each time the condition is true don't send me again*/
        messageSent=true;  
    }
    
  }
  else
  {
    messageSent = false;
  }
}

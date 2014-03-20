/*
Example illustrates sending SMS to my phone to notify me that the Temperature in my home 
increased and exceeded certain limit 
*/

/*Including OneSheeld Library*/
#include <OneSheeld.h>

/*Reserve a variable for sending only one time*/
boolean messageSent=true;

void setup () 
{
 /*Start UART communication on baudrate 57600*/
 OneSheeld.begin(); 
}


void loop () 
{
  /*Always check the Temperature in the House*/
  if (TemperatureSensor.getValue()>30)
  {
    /*Check that the message sent only once and not annoy you by always sending in loop*/
    if(messageSent)
    {   
        /*Send me the Message*/ 
        SMS.send("+01286077028","Room Temperature is Bigger than 30 Degree");
        /*Reset the variable with false as each time the condition is true don't send me again*/
        messageSent=false;  
    }
    
  }
}

/*
Example illustrates Sensing the Pressure using the Smart Phone Pressure Sensor and when 
exceeded a limit sends an SMS to my phone
*/

/*Include OneSheeld Library*/
#include <OneSheeld.h>

/*Reserve a boolean*/
boolean messageSent=false;

void setup () 
{
  /*Start Communication*/
  OneSheeld.begin();
}


void loop () 
{
  /*Always get the Value of the Pressure and if exceeded send the message*/
  /*since 1008 was the value read from the sensor in the current state*/
  if (PressureSensor.getValue()>1008)
  {
    /*Checking so as the message is sent once and don't always annoy you*/
    if (messageSent==false)
    {
      /*Send the SMS to my mobile number*/
      SMS.send("+0201286077028","Pressure is getting high in HERE");
      /*Reset the value of the messageSent so as not to always let the phone send you the SMS*/
      messageSent=true;
    }
  }
}

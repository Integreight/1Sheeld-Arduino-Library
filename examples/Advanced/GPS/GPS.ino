/*

GPS Shield Example

This example shows an application on 1Sheeld's GPS shield.

By using this example, you can send an SMS when the smartphone
is in a hundred meters distance from a fixed coordinates you
provide.

OPTIONAL:
To reduce the library compiled size and limit its memory usage, you
can specify which shields you want to include in your sketch by
defining CUSTOM_SETTINGS and the shields respective INCLUDE_ define. 

*/

#define CUSTOM_SETTINGS
#define INCLUDE_GPS_SHIELD
#define INCLUDE_SMS_SHIELD

/* Include 1Sheeld library.*/
#include <OneSheeld.h>

/* Define a boolean flag. */
boolean isInRange = false;

void setup() 
{
  /* Start communication.*/
  OneSheeld.begin();
}

void loop()
{
   /* Always check if the smartphone's GPS and a given latitude and longitude are in a range of 100 meters. */
  if(GPS.isInRange(30.0831008,31.3242943,100))
  {
    if(!isInRange)
    {
      /* Send SMS. */
      SMS.send("+1234567890","Smartphone is In Range.");
      isInRange = true;
    }
    
  }
  else 
  {
    if(isInRange)
    {
      /* Send SMS. */ 
      SMS.send("1234567890","Smartphone is not In Range.");
      isInRange = false;
    }
    
  }
}

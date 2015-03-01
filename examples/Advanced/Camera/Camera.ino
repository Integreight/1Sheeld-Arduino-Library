/*

Camera Shield Example

This example shows an application on 1Sheeld's camera shield.

By using this example, you can take a photo using your phone's
camera if the light sensor reads data above a certain threshold.

*/

/* Include 1Sheeld library. */ 
#include <OneSheeld.h>

void setup()
{
  /* Start communication. */
  OneSheeld.begin();
}

void loop()
{
  /* Always get the value of the light sensor and make sure it is in a certain range. */
  if(LightSensor.getValue()<100 && LightSensor.getValue()>0)
  {
    /* Turn on the camera's flash while capturing. */
    Camera.setFlash(ON);
    /* Take a photo using the phone's rear camera. */
    Camera.rearCapture();
    /* Delay for 5 seconds. */
    OneSheeld.delay(5000);
  }
  
}

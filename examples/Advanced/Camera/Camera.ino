/*

Camera Shield Example

This example shows an application on 1Sheeld's camera shield.

By using this example, you can take a photo using your phone's
camera if the light sensor reads data above a certain threshold.

OPTIONAL:
To reduce the library compiled size and limit its memory usage, you
can specify which shields you want to include in your sketch by
defining CUSTOM_SETTINGS and the shields respective INCLUDE_ define. 

*/

#define CUSTOM_SETTINGS
#define INCLUDE_CAMERA_SHIELD
#define INCLUDE_LIGHT_SENSOR_SHIELD

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

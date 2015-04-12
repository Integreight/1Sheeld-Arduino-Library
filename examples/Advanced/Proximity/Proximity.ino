/*

Proximity Shield Example

This example shows an application on 1Sheeld's proximity shield.

By using this example, you can campture a picture and
send a SMS when the value of the smartphone's proximity
sensor exceeds a certain limit.

OPTIONAL:
To reduce the library compiled size and limit its memory usage, you
can specify which shields you want to include in your sketch by
defining CUSTOM_SETTINGS and the shields respective INCLUDE_ define. 

*/

#define CUSTOM_SETTINGS
#define INCLUDE_PROXIMITY_SENSOR_SHIELD
#define INCLUDE_CAMERA_SHIELD
#define INCLUDE_SMS_SHIELD

/* Include 1Sheeld library. */
#include <OneSheeld.h>

void setup()
{
  /* Start communication. */
  OneSheeld.begin();
  /* Call a specific function when the proximity value change. */
  ProximitySensor.setOnValueChange(&OnValueChange);
}

void loop()
{
  /* Do nothing. */
}

void OnValueChange(byte value)
{
  /* Always check if the proximity sensor value doesn't equal to zero cm. */
  if (ProximitySensor.getValue() == 0)
  {
    /* Set the flash of the Camera. */
    Camera.setFlash(ON);
    /* Take a photo. */
    Camera.rearCapture();
    /* Send the SMS. */
    SMS.send("1234567890","Something or Someone passed near the place!");
  }
}
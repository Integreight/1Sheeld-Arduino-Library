/*

Terminal Shield Example

This example shows an application on 1Sheeld's Terminal shield.

By using this example, you can check the change of values in the 
Accelerometer sensor.

*/

/* Include 1Sheeld library. */
#include <OneSheeld.h>


void setup()
{
  /* Start communication. */
  OneSheeld.begin();
}

void loop ()
{
  /* Print AccelerometerX. */
  Terminal.print("Acc X: ");
  /* Print Accelerometer X-axis Value. */
  Terminal.println(AccelerometerSensor.getX());
  /* Print AccelerometerY. */
  Terminal.print("Acc Y: ");
  /* Print Accelerometer Y-axis Value. */
  Terminal.println(AccelerometerSensor.getY());
  /* Print AccelerometerZ. */
  Terminal.print("Acc Z: ");
  /* Print Accelerometer Z-axis Value. */ 
  Terminal.println(AccelerometerSensor.getZ());
}

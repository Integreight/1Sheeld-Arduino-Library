/*Example illustrates the light intensity of the room using your Smart Phone Light Sensor, when the light reaches its maximum, the LED is OFF
when the light FADES OFF, the LEDs FADES ON gradually (i.e:for this example put your phone on a clear place in the middle of the room to get the maximum room light intensity and don't Move the Smartphone)
*/


/*Include OneSheeld Library*/ 
#include<OneSheeld.h>

/*maximum room light intensity*/ 
long maxLightIntensity=0;
/*maximum ratio of the maximum value 255(8bits) to be sent by arduino along with the maximum value got by the Ligh Sensor*/
float ratio=0;
/*value of current value of the Light Sensor and the maximum ratio*/
long ledValue=0;
/*current value from the Light Sensor*/
unsigned long lightValue;
/*Led on 10*/
int ledPin = 10;
void setup ()
{
  /*Start Communication*/
  OneSheeld.begin();
  /*Set ledPin OUTPUT*/
  pinMode(ledPin,OUTPUT);
}


void loop()
{
  /*if the sensor value is larger than maximum, make it maximum (Don't put the phone on direct light*/
  /*as it will be a large value which will not let the application work properly*/
  if(LightSensor.getValue()>maxLightIntensity)
  {
    maxLightIntensity=LightSensor.getValue();
    ratio=255/(float)maxLightIntensity;
  }
  /*Get the light values that will be processed*/
  lightValue=LightSensor.getValue();
  /*Check if the light value is too much bigger than the max then let the max*/
  if(lightValue > maxLightIntensity)
  {
    lightValue=maxLightIntensity;
  }
  /*Process on the light value using the ratio calculated and take the diffrence of the value*/ 
  /*with 255*/
  ledValue=255-lightValue*ratio;
  
  /*Accuracy*/
  if(ledValue <10)
  {
    /*Led goes Off if ledValue is less than 10 (accuracy)*/ 
    analogWrite(ledPin,0);
  }
  else
  {
    /*Let the led On by certain Value*/
    analogWrite(ledPin,ledValue);  
  }
  
}

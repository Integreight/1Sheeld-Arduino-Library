/*
Example illustrates the light intensity of the room using the Smart Phones 
Light Sensor and then as when the light reaches it's maximum the LED is OFF
when the light FADES OFF the LEDs FADES ON gradually
i.e: put your phone on a clear place in the middle of the room so as to get the maximum 
     room light intensity and make it still
*/

/*Include OneSheeld Library*/ 
#include<OneSheeld.h>

/*Reserving a variable to get the maximum room light intensity*/ 
 long maxLightIntensity=0;
/*Reserving a variable to get the maximum ratio of the maximum value 255(8bits) to be sent*/
/*by arduino along with the maximum value got by the Ligh Sensor*/
float ratio=0;
/*Reserving a variable to get the value of multiplication of current value got from the*/
/*Light Sensor and the maximum ratio*/
long ledValue=0;
/*Reserving a varaible to get the current value from the Light Sensor*/
unsigned long lightValue;
/*Led on 10*/
int ledPin = 10;
void setup ()
{
  /*Start Communication*/
  OneSheeld.begin();
  /*Set ledPin OUTPUT or you could set any other PWM pins only(~3/~5/~6/~9/~10/~11)*/
  pinMode(ledPin,OUTPUT);
}


void loop()
{
  /*Always get the Light Intensity and check out if it was the largest value or not*/
  /*and if the value is larger take the larger (Don't put the phone on direct light*/
  /*as it will be a large value which will not let the application work properlly only with*/
  /*the largest Light Intensity Value)*/
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
    /*Led don't ignite if ledValue is less than 10 (accuracy)*/ 
    analogWrite(ledPin,0);
  }
  else
  {
    /*Let the led ignite at the value calculated*/
    analogWrite(ledPin,ledValue);  
  }
  
}

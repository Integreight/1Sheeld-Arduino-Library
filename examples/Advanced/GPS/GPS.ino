/*
Example illustrates the use of the Global Positioning system 
of the Smart Phone giving a Fixed location and calculating the 
distance between the fixed coordinates and the new coordinates 
comming from the GPS of the Smart Phone
*/

/*including the OneSheeld Library*/
#include <OneSheeld.h>

/*Reserving a float variable to get the distance*/
float distance;
/*Led on 13*/
int ledPin = 13;
/*Reserving boolean*/
boolean InRange = false;
void setup() 
{
  /*Start Communication*/
  OneSheeld.begin();
  /*LedPin OUTPUT*/
  pinMode(ledPin,OUTPUT);
}


void loop()
{
  
  /*always get the distance between the two coordinates getDistance(Fixed Longitude,Fixed Lattitude)*/
  distance=GPS.getDistance(30.0831008,31.3242943);
   /*always check if the new coordinate is in the range given by meters as*/ 
   /*isInRange(Fixed Longitude,Fixed Lattitude,Range"in meters")*/   
  if(GPS.isInRange(30.0831008,31.3242943,100))
  {
    if(InRange == false)
    {
      /*ignite the LED*/
      SMS.send("+201286077028","Object is In Range");
      InRange = true;
    }
    
  }
  else 
  {
    if(InRange == true)
    {
      /*take off the LED*/ 
      SMS.send("+201286077028","Object is not In Range");
      InRange = false;
    }
    
  }
}

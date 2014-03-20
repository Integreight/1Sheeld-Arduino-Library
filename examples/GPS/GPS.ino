/*
Example illustrates the use of the Global Positioning system 
of the Smart Phone giving a Fixed location and calculating the 
distance between the fixed coordinates and the new coordinates 
comming from the GPS of the Smart Phone
*/

/*including the OneSheeld Library*/
#include <OneSheeld.h>

/*reserving a float variable to get the distance*/
float distance;

void setup() 
{
  /*Starting the UART communication on baudrate 57600*/
  OneSheeld.begin();
  /*set pin 13 as OUTPUT*/
  pinMode(13,OUTPUT);
}


void loop()
{
  
  /*always get the distance between the two coordinates getDistance(Fixed Longitude,Fixed Lattitude)*/
  distance=GPS.getDistance(30.0831008,31.3242943);
   /*always check if the new coordinate is in the range given by meters as*/ 
   /*isInRange(Fixed Longitude,Fixed Lattitude,Range"in meters")*/   
  if(GPS.isInRange(30.0831008,31.3242943,100))
  {
    /*ignite the LED*/
    digitalWrite(13,HIGH);
  }
  else 
  {
    /*take off the LED*/ 
    digitalWrite(13,LOW);
  }
}

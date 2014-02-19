#include <OneSheeld.h>

float value;
void setup() 
{
  OneSheeld.begin();
  pinMode(13,OUTPUT);
}


void loop()
{
  //value = GPS.getDistance(30.0831008,31.3242943);
  if(GPS.isInRange(30.0831008,31.3242943,100))
  {
    digitalWrite(13,HIGH);
  }
  else 
  {
    digitalWrite(13,LOW);
  }
}

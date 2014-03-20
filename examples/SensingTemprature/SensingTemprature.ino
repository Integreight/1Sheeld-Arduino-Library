/*
Example illustrates Sensing the temperature of 
a room and Buzzing if the temperature exceeded a 
certain value
*/

#include <OneSheeld.h>

/*Reserving a varriable for the Temperature value and initiallizing it by zero*/
char tempvalue=0;

void setup () 
{
   
  /*Starting the UART communication on baud rate 57600*/
   OneSheeld.begin(57600);
   
}

/*Always get temperature values from the Temperature Sensor of the mobile*/
void loop()
{
    /*Storing the temperature value*/
    tempvalue=Temp.getDegree();
    /*Buzz if the Temperature exceeds 20 degrees in Celsuis*/ 
    if (tempvalue>=20)
    {
      /*Buzzing*/
      Buzzer.buzzOn();
      /*Delay 10 seconds*/
     delay(10000);
      /*Stop Buzzing*/  
      Buzzer.buzzOff();
    }
    
}




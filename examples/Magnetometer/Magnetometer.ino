/*
Example Illustrate the Magnetic Field in the Enviroment given a natural magnetic field 
of a safe enviroment and calculating the current magnetic field and compares between them 
when exceeded a limit the Sheeld will send a notification tells that the magnetic Strength
had been increased
*/

/*Including the OneSheeld Library*/
#include <OneSheeld.h>

/*Reserve a variable*/
boolean notificationsent=false;
void setup ()
{
  /*Start UART communication on baudrate 57600*/
  OneSheeld.begin();
  pinMode(13,HIGH);
}

void loop () 
{
  
  /*Checkout if the magnetic strength exceeded certain value(normal magnetic field far away from
  devices and electronical and any object that conducts magnetic field)*/
  if (MagnetometerSensor.magneticStrength()>50.115)
  {
        /*This assures that notification will be sent only one time in this loop*/ 
        if (notificationsent==false){
        /*Notify the Smart Phone*/
        Notification.notifyPhone("Danger: Magnetic field increased checkout what's the problem");
        /*Initialize the variable with true so as to not always send a notification and annoy you*/
        notificationsent=true;
      }
  }
  
}

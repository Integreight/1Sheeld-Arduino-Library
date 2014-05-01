/*Example Illustrates Sending an Email using the Toggle Shield button 
when pressed send the Email
*/

/*Including OneSheeld Library*/
#include <OneSheeld.h>

void setup () 
{
  /*Start UART communication on baudrate 57600*/
  OneSheeld.begin();
  /*Set pin 13 as INPUT*/
  pinMode(13,INPUT);
}

void loop()
{
  /*Check if pin 13 is High using the Toggle Button in the Application*/
  if(digitalRead(13)==HIGH)
  {
    /*If the Button is High Send this Email with the email address and subject and
    body of message*/
    Email.send("islam@integreight.com","Greetings","hi From Integreight");
    /*delay a second for not sending excessive amount of loop due to speed of the loop*/ 
    delay(1000);
  }
}

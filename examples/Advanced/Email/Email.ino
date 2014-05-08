/*Example Illustrates Sending an Email using the Toggle Shield button 
when pressed send the Email
*/

/*Including OneSheeld Library*/
#include <OneSheeld.h>

/*Button Pin 13*/
int buttonPin = 13;
/*Reserve a boolean*/
boolean isEmailSent = false;

void setup () 
{
  /*Start Communication*/
  OneSheeld.begin();
  /*buttonPin INPUT*/
  pinMode(buttonPin,INPUT);
}

void loop()
{
  /*Check if buttonPin is High using the Toggle Button in the Application*/
  if(digitalRead(buttonPin) == HIGH)
  {
    if(isEmailSent == false)
    {
      /*If the Button is High Send this Email with the email address and subject and
      body of message*/
      Email.send("islam@integreight.com","Greetings","hi From Integreight");
      /*Reset the boolean value*/
      isEmailSent = true;
    }
  }
}

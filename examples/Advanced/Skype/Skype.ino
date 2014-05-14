/*
Example illustrates the Skype shield Application when you press the button you will call 
a certain skype account you set in the sketch
*/

/*Include OneSheeld Library*/ 
#include <OneSheeld.h>

/*Reserve a boolean*/
boolean called=false;
/*Button on 12*/
int buttonPin = 12;
void setup () 
{
  /*Start Communication*/
  OneSheeld.begin();
  /*buttonPin as INPUT*/
  pinMode(buttonPin,INPUT);
}


void loop () 
{
  /*Always check buttonPin if it's high, Skype the account*/
  if (digitalRead(buttonPin) == HIGH)
  {
    /*To call only once and not go on calling while looping*/
    if(called=false)
    {
      /*Call your callee*/
      Skype.call("echo123");  
      /*Reset the variable*/
      called=true;
    }
  }
}


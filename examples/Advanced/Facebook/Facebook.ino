/*
Example illustrates Updating status on Facebook everyday at 
8 Am 
*/


/*Include OneSheeld Library*/
#include <OneSheeld.h>
/*Include LiquidCrystal Library*/
#include <LiquidCrystal.h>

/*Initialize the LCD interfacing pins*/
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

/*Variables for the Clock (Hour-minutes-seconds)*/
byte Hours;
byte Minutes;
byte Seconds;

void setup () 
{
  /*Start Communication*/
  OneSheeld.begin();
  /*Start Clock Shield*/
  Clock.begin();
  /*Set up the LCD's number of columns and rows*/ 
  lcd.begin(16, 2);
  pinMode(9,OUTPUT);
  analogWrite(9,0);
}


void loop ()
{
  Hours   = Clock.getHours();
  Minutes = Clock.getMinutes();
  Seconds = Clock.getSeconds();

  /*Check the Clock*/
  if(Hours == 8 && Minutes == 0 && Seconds == 0)
  {
    Facebook.updateStatus("Good Morning");
    /*LCD indication*/
    lcd.print("Status Updated");
    /*Make a delay*/
    delay(2000);
    lcd.clear();
  }
}

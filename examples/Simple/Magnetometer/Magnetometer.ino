/*
Example illustrates calculating the Magnetic Stength and 
display the Value on LCD
*/


/*Include OneSheeld Library*/
#include <OneSheeld.h>
/*Include Arduino's LCD Library*/
#include <LiquidCrystal.h>

/*Initialize the library with the numbers of the interface pins*/
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

/*Led Pin on 13*/
int ledPin = 13 ;

void setup () 
{
  /*Start Communication*/
  OneSheeld.begin();
  /*Set up the LCD's number of columns and rows:*/
  lcd.begin(16, 2);
  /*Set the ledPin as OUTPUT*/
  pinMode(ledPin,OUTPUT);
  pinMode(9,OUTPUT);
  /*Set the Contrast of the LCD by using values 0(dark)-->255(bright)*/
  analogWrite(9,0);
  lcd.print("MagneticStrength");
  lcd.setCursor(7,1);
  lcd.print("Tesla");
  
}


void loop () 
{
  /*Set the cursor*/
  lcd.setCursor(0,1);
  /*Display the Magnetic Strength*/
  lcd.print(MagnetometerSensor.getMagneticStrength());
  delay(1000);
}
/*

Magnetometer Shield Example

This example shows an application on 1Sheeld's magnetometer shield.

By using this example, you can display the magnetic field
strength read by the smartphone's on a hardware LCD.

OPTIONAL:
To reduce the library compiled size and limit its memory usage, you
can specify which shields you want to include in your sketch by
defining CUSTOM_SETTINGS and the shields respective INCLUDE_ define. 

*/

#define CUSTOM_SETTINGS
#define INCLUDE_MAGNETOMETER_SENSOR_SHIELD

/* Include 1Sheeld library. */
#include <OneSheeld.h>
/* Include LiquidCrystal library. */
#include <LiquidCrystal.h>

/* Initialize the LCD interfacing pins. */
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

/* A name for the LED on pin 13. */
int ledPin = 13 ;
/* LCD contrast level on pin 9. */
int lcdContrast = 9;

void setup() 
{
  /* Start communication. */
  OneSheeld.begin();
  /* Set up the LCD's columns and rows. */ 
  lcd.begin(16, 2);
  /* Set the LED pin as output. */
  pinMode(ledPin,OUTPUT);
  /*Set lcd contrast pin as output. */ 
  pinMode(lcdContrast,OUTPUT);
  /* Use a range from 0 till 255 to control the contrast of the LCD. */
  analogWrite(lcdContrast,0);
  /* Print a title and a unit. */
  lcd.print("MagneticStrength");
  /* Move the cursor. */
  lcd.setCursor(7,1);
  lcd.print("Tesla");
}

void loop() 
{
  /* Move the cursor. */
  lcd.setCursor(0,1);
  /* Display the magnetic strength. */
  lcd.print(MagnetometerSensor.getMagneticStrength());
  /* Wait for 1 second. */
  OneSheeld.delay(1000);
}
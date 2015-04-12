/*

LCD Shield Example

This example shows an application on 1Sheeld's LCD shield.

By using this example, you can print some text on the
LCD shield available in our app.

OPTIONAL:
To reduce the library compiled size and limit its memory usage, you
can specify which shields you want to include in your sketch by
defining CUSTOM_SETTINGS and the shields respective INCLUDE_ define. 

*/

#define CUSTOM_SETTINGS
#define INCLUDE_LCD_SHIELD

/* Include 1Sheeld library. */ 
#include <OneSheeld.h>

/* A name for a button on pin 12. */
int buttonPin = 12;

void setup() 
{
  /* Start communication. */
  OneSheeld.begin();
  /* Set the button pin as input. */
  pinMode(buttonPin,INPUT);  
}

void loop()
{
  /* Always check the button pin if pressed. */
  if(digitalRead(buttonPin) == HIGH)
  {
   /* Begin the LCD cursor at the first row and first column. */
   LCD.begin();
   /* Blink the cursor and for 5 seconds. */
   LCD.blink();
   OneSheeld.delay(5000);
   /* Stop blinking. */
   LCD.noBlink();
   /* Write some characters. */
   LCD.write('A');
   LCD.write('B');
   LCD.write('C');
   /* Wait for 2 seconds. */
   OneSheeld.delay(2000);
   /* Clear the LCD. */
   LCD.clear();
   /* Print "Hello, World!" */
   LCD.print("Hello, World!");
   /* Set the cursor to begin writing from the second row and first column. */
   LCD.setCursor(1,0);
   /* Print "This is 1Sheeld" */ 
   LCD.print("This is 1Sheeld");
   /* Wait 10 seconds. */  
   OneSheeld.delay(10000);
   /*Clear LCD*/
   LCD.clear();
   /* Print "Closing!" */
   LCD.print("Closing!");
   /* Wait for 2 seconds. */
   OneSheeld.delay(10000);
  }
  
  
   
}

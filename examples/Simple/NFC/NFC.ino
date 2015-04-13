/*

NFC Shield Example

This example shows an application on 1Sheeld's NFC shield.

By using this example, you can control an RGB LED with NFC cards
to light up certain colors.

OPTIONAL:
To reduce the library compiled size and limit its memory usage, you
can specify which shields you want to include in your sketch by
defining CUSTOM_SETTINGS and the shields respective INCLUDE_ define. 

*/

#define CUSTOM_SETTINGS
#define INCLUDE_NFC_SHIELD
#define INCLUDE_TERMINAL_SHIELD

/* Inlcude 1Sheeld library. */
#include <OneSheeld.h>

/* Stings to be compared by data from the NFC card. */
char * redArray = "red";
char * greenArray = "green";
char * blueArray = "blue";

/* Set a RGB LED on pin 8,9 and 10. */
int red = 8;
int green = 9;
int blue = 10;

void setup() {
  // put your setup code here, to run once:
  /* Start communication. */
  OneSheeld.begin();
  /* Subscribe to a new scanned tag CallBack. */
  NFC.setOnNewTagScanned(&tagFunction);
  /* LED pin modes OUTPUT.*/
  pinMode(red, OUTPUT); 
  pinMode(green, OUTPUT); 
  pinMode(blue, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

}


void tagFunction(NFCTag &myTag)
{
  /* Subscribe to record parsed data Callback. */
  myTag.setOnRecordParsedDataResponse(&responseFunction);
  /* Send to check the parsed data in first Record. */
  myTag.getRecord(0).queryParsedData();
}

void responseFunction(byte recordNumber , char data[])
{
  /* Check response and compare data. */
  if(!strcmp(data,redArray))
  {
    Terminal.println("Red");
    digitalWrite(red, HIGH);
    digitalWrite(green, LOW);
    digitalWrite(blue, LOW);
  }
  else if(!strcmp(data,blueArray))
  {
    Terminal.println("blue");
    digitalWrite(red, LOW);
    digitalWrite(green, LOW);
    digitalWrite(blue, HIGH);
  }
  else if(!strcmp(data,greenArray))
  {
    Terminal.println("green");
    digitalWrite(red, LOW);
    digitalWrite(green, HIGH);
    digitalWrite(blue, LOW);
  }
}

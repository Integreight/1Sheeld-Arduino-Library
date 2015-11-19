/*

NFC Shield Example

This example shows an application on 1Sheeld's NFC shield.

By using this example, you can control an RGB LED color using NFC tags.

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

/* Reserve some color names as char arrays. */
const char * redArray = "red";
const char * greenArray = "green";
const char * blueArray = "blue";

/* Set a RGB LED on pin 8,9 and 10. */
int red = 8;
int green = 9;
int blue = 10;

void setup()
{
  /* Start communication. */
  OneSheeld.begin();
  /* Subscribe to the new tag scanned event. */
  NFC.setOnNewTagScanned(&tagFunction);
  /* Subscribe to on Tag error event. */
  NFC.setOnError(&tagErrorFunction);
  /* Set the RGB LED pins as output. */
  pinMode(red, OUTPUT); 
  pinMode(green, OUTPUT); 
  pinMode(blue, OUTPUT);
}

void loop()
{
  /* Leave the loop empty. */
}

/* A function to be called once a new tag is scanned. */
void tagFunction(NFCTag &myTag)
{
  /* Create and object of type NFCRecord. */
  NFCRecord &myRecordNumber0 = myTag.getRecord(0);
  /* Subscribe to record parsed data response event. */
  myTag.setOnRecordParsedDataResponse(&responseFunction);
  /* 
  /* Check if there's a record with number 0 in Tag. */
  if(!myRecordNumber0.isNull())
  {
    /* Parse and query the data in the first record. */
    myRecordNumber0.queryParsedData();  
  }
  else
  {
    /* Print out no record found. */
    Terminal.println("No Record found"); 
  }
}

/* A function to be called once a new parsed data is received. */
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

/* OnError event. */
void tagErrorFunction(byte errorNumber)
{
  /* Switch on error number. */
  switch(errorNumber)
  {
    case INDEX_OUT_OF_BOUNDS: Terminal.println("INDEX_OUT_OF_BOUNDS");break;
    case RECORD_CAN_NOT_BE_PARSED: Terminal.println("RECORD_CAN_NOT_BE_PARSED");break;
    case TAG_NOT_SUPPORTED: Terminal.println("TAG_NOT_SUPPORTED");break;
    case NO_ENOUGH_BYTES: Terminal.println("NO_ENOUGH_BYTES");break;
    case TAG_READING_ERROR: Terminal.println("TAG_READING_ERROR");break;
    case RECORD_NOT_FOUND: Terminal.println("RECORD_NOT_FOUND");break;
  }
}
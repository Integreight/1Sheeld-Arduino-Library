/*

Barcode Scanner Shield Example

This example shows an application on 1Sheeld's barcode scanner shield.

By using this example, you can scan a 2D (QR/Data Matrix) barcode with
an Email category and send the email directly using the email shield to
the recipient.

OPTIONAL:
To reduce the library compiled size and limit its memory usage, you
can specify which shields you want to include in your sketch by
defining CUSTOM_SETTINGS and the shields respective INCLUDE_ define. 

*/

#define CUSTOM_SETTINGS
#define INCLUDE_BARCODE_SCANNER_SHIELD
#define INCLUDE_TERMINAL_SHIELD
#define INCLUDE_EMAIL_SHIELD

/* Include 1Sheeld library. */
#include <OneSheeld.h>

/* Declare some arrays to receive data from 2D code. */
char sendTo[50];
char subject[50];
char body[140];

void setup() {
  /* Start communication. */
  OneSheeld.begin();
  /* Subscribe to new barcode callback. */
  BarcodeScanner.setOnNewBarcodeScanned(&newScannedFunction);
  /* Subscribe to parameter data callback. */
  BarcodeScanner.setOnParameterValueResponse(&getParameterFunction);
  /* Subscribe to the error callback. */
  BarcodeScanner.setOnError(&errorFunction);
}

void loop() 
{
  /* Leave the loop function empty. */
}

/* On new barcode scanned function. */
void newScannedFunction(byte format,byte category,int maxLength,char * data)
{
  /* Check if the code scanned is a QR code or a data matrix code. */
  if(format == QRCODE || format == DATA_MATRIX)
  {
    /* Check if the code scanned with email category type. */
    if(category == CODE_EMAIL)
    {
      /* Terminal line for debugging. */
      Terminal.println("Email scanned from barcode.");

      /* Query parameters from barcode scanner. */
      BarcodeScanner.queryParameterValue("mailto");
      BarcodeScanner.queryParameterValue("subject");
      BarcodeScanner.queryParameterValue("body");
    }
  }
}

void getParameterFunction(char * key, char* value)
{
  /* Save incoming parameter data.*/
  int i = 0;
  if(!strcmp(key,"mailto"))
  {
    /* Save recipient email address. */
    while(value[i]!='\0')
    {
     sendTo[i] = value[i];
     i++; 
    }
  }else if(!strcmp(key,"subject"))
  {
    /* Save email subject. */
    while(value[i]!='\0')
    {
     subject[i] = value[i];
     i++; 
    }
  }else if(!strcmp(key,"body"))
  {
    /* Save email body. */
    while(value[i]!='\0')
    {
     body[i] = value[i];
     i++; 
    }
  }

  /* Check if the arrays are not empty send the email. */
  if(sendTo[0]!=0 && subject[0]!=0 && body[0]!=0)
  {
    /* Send email. */
    Email.send(sendTo,subject,body);

    /* Empty the arrays. */
    for(int j=0;j<20;j++)
    {
      sendTo[i] = 0;
      subject[i] = 0;
      body[i]=0;
    }
  }
}

void errorFunction(byte errorData)
{
  /* Switch on error and print it on the terminal. */
  switch(errorData)
  {
    case BARCODE_NOT_SUPPORTED: Terminal.println("Barcode is not supported");break;
    case BARCODE_SCANNING_ERROR: Terminal.println("Barcode scanning error");break;
    case WRONG_PARAMETER: Terminal.println("Wrong parameter");break;
    case NOT_ENOUGH_BYTES: Terminal.println("No enough bytes");break;
    case CATEGORY_NOT_SUPPORTED: Terminal.println("Category not supported");break;
  }
}

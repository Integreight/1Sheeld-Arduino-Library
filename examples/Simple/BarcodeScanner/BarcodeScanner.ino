/*

Barcode Scanner Shield Example

This example shows an application on 1Sheeld's barcode scanner shield.

By using this example, you can display barcode data on your smartphone
screen using the terminal shield.

OPTIONAL:
To reduce the library compiled size and limit its memory usage, you
can specify which shields you want to include in your sketch by
defining CUSTOM_SETTINGS and the shields respective INCLUDE_ define. 

*/

#define CUSTOM_SETTINGS
#define INCLUDE_BARCODE_SCANNER_SHIELD
#define INCLUDE_TERMINAL_SHIELD

/* Include 1Sheeld library. */
#include <OneSheeld.h>

void setup() 
{
  /* Start communication. */
  OneSheeld.begin();
  /* Subscribe to the error callback. */
  BarcodeScanner.setOnError(&errorFunction);
}

void loop() {
  /* Check if a new barcode is scanned. */
  if(BarcodeScanner.isNewBarcodeScanned())
  {
    /* Print max data length saved in barcode. */
    Terminal.println(BarcodeScanner.getMaxDataLength());

    /* Print first 128 bytes of barcode data. */
    Terminal.println(BarcodeScanner.getData());

    /* If the barcode has more that 128 bytes, query its next data bytes. */
    if(BarcodeScanner.getMaxDataLength() > 128)
    {
      /* Query the next 128 (default) bytes. */ 
      BarcodeScanner.queryNextDataBytes();
    }
  }
  /* Check if the data is the next bytes of same barcode. */
  if(BarcodeScanner.isNextDataBytesReceived())
  {
    /* Check if the barcode data was fully sent. */
    if(!BarcodeScanner.isFullySent())
    {
      /* Query the next 128 (default) bytes. */ 
      BarcodeScanner.queryNextDataBytes();
    }
    else
    {
      /* Print data is fully sent from barcode shield. */
      Terminal.println("Fully sent");
    }
    /* Print the next data bytes. */
    Terminal.println(BarcodeScanner.getData());
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



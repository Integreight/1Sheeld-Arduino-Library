/*

NFC Shield Example

This example shows an application on 1Sheeld's NFC shield.

By using this example, you can check records number, used size and
maximum size of NFC tags.

OPTIONAL:
To reduce the library compiled size and limit its memory usage, you
can specify which shields you want to include in your sketch by
defining CUSTOM_SETTINGS and the shields respective INCLUDE_ define. 

*/

#define CUSTOM_SETTINGS
#define INCLUDE_NFC_SHIELD
#define INCLUDE_TERMINAL_SHIELD

/* Include 1Sheeld library. */
#include <OneSheeld.h>


void setup()
{
  /* Start Communication. */
  OneSheeld.begin();
}

void loop()
{
  /* Check if there's a new tag scanned. */
  if(NFC.isNewTagScanned())
  {
    /* Get that last scanned tag. */
    NFCTag & myTag = NFC.getLastTag();
    /* Print all the data about the scanned tag. */
    Terminal.print("Number of Records in Tag = ");
    /* Print number of records. */
    Terminal.println(myTag.getNumberOfRecords());
    /* Print tag used size. */
    Terminal.print("Used Tag Size = ");
    Terminal.println(myTag.getSize());
    /* Print tag maximum size. */
    Terminal.print("Maximum Tag Size = ");
    Terminal.println(myTag.getMaxSize());    
  }
}

/*

NFC Shield Example

This example shows an application on 1Sheeld's NFC shield.

By using this example, you can check records number, used size and Max size of Tags.

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
  /* Check if there's a new Tag Scanned. */
  if(NFC.isNewTagScanned())
  {
    /* Get last tag scanned. */
    NFCTag & myTag = NFC.getLastTag();
    /* Print all data about the scanned Tag. */
    Terminal.print("Number of Records in Tag = ");
    /* Print number of Records. */
    Terminal.println(myTag.getNumberOfRecords());
    /* Print used size of Tag. */
    Terminal.print("Used Tag Size = ");
    Terminal.println(myTag.getSize());
    /* Print max. size of Tag. */
    Terminal.print("Maximum Tag Size = ");
    Terminal.println(myTag.getMaxSize());    
  }
}

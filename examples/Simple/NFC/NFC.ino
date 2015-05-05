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
    Terminal.print("Tag id length = ");
    Terminal.println(myTag.getIdLength());
    switch(myTag.getRecord(0).getTypeCategory())
    {
      case TNF_UNKNOWN : Terminal.println("TNF_UNKNOWN");break;
      case TNF_EMPTY : Terminal.println("TNF_EMPTY");break;
      case TNF_EXTERNAL_TYPE : Terminal.println("TNF_EXTERNAL_TYPE");break;
      case TNF_MIME_MEDIA : Terminal.println("TNF_MIME_MEDIA");break;
      case TNF_UNCHANGED : Terminal.println("TNF_UNCHANGED");break;
      case TNF_ABSOLUTE_URI : Terminal.println("TNF_ABSOLUTE_URI");break;
      case RTD_TEXT : Terminal.println("RTD_TEXT");break;
      case RTD_URI : Terminal.println("RTD_URI");break;
      case RTD_UNSUPPORTED : Terminal.println("RTD_UNSUPPORTED");break;
    }
  }
}
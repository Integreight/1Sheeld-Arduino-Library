/*

RemoteOneSheeld Example #1

This example shows an application on remote 1Sheeld's feature.

By using this example you can hook up a toggle button to your 1Sheeld system and control an
LED on another 1Sheeld system through the internet. 

*/
 
/* Include 1Sheeld library. */
#include <OneSheeld.h>
 
/*

Instantiate an object from RemoteOneSheeld Library and insert the unique address of the 
remote system given you in the application about dialog.

*/

RemoteOneSheeld usaSheeld ("-----REMOTE-1SHEELD-ADDRESS-----");

int remotePin = 11;
int ledPin = 13;

void setup()
{
  /* Start communication. */
  OneSheeld.begin();
  /* Listen to the remote 1Sheeld. */
  OneSheeld.listenToRemoteOneSheeld(&usaSheeld);
  /* Subscribe to a certain pin on the remote 1Sheeld system in USA for instance. */
  usaSheeld.subscribeToChanges(remotePin);
  /* Set a certain function to be invoked once the remote system responds with the state 
    of the pin. 
  */
  usaSheeld.setOnSubscribeOrDigitalChange(&toggleLed);
  /* Set an LED to pin 13. */ 
  pinMode(ledPin,OUTPUT);
 
}

void loop()
{
 /* Send any sentences to be said out loud in the other smartphone. */
  if(VoiceRecognition.isNewCommandReceived())
  {
    /* Send the Command to the USA 1Sheeld system. */
    usaSheeld.sendMessage("USA",VoiceRecognition.getLastCommand());  
  }

}


/* Function to Toggle the LED according to the state coming from the remote 1Sheeld system. */
void toggleLed(byte pinNumber , bool remotePinValue)
{
  /* Turn on the LED. */
  digitalWrite(ledPin,remotePinValue); 
}

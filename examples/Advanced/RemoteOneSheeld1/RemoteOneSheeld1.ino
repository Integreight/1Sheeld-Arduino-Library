/*

 RemoteOneSheeld Example

 This example shows an application on 1Sheeld's Remote Feature.
 
 By using this example you can hook up a toggle button to your 1Sheeld system and control an
 Led on another 1Sheeld system exists around the globe. 
 
 */
 
 /* Include 1Sheeld library. */
 #include <OneSheeld.h>
 
 /* Insatntiate an Object from RemoteOneSheeld Library and insert the unique address of the 
 remote system given you in the application.
    You can get the remote address from the application by pressing Menu >> About , and you 
 can share the address Id with anyone by pressing shareId. 
 */
 RemoteOneSheeld usaSheeld ("place the remote shared ID here");
 
 int remotePin = 11;
 int ledPin = 13;
 
 void setup()
 {
   /* Start communication. */
   OneSheeld.begin();
   /* Listen to the remote 1Sheeld. */
   OneSheeld.listenToRemoteOneSheeld(&usaSheeld);
   /* Subscribe to a certain pin on the remote 1Sheeld system in USA. */
   usaSheeld.subscribeToChanges(remotePin);
   /* Set a certain function to be invoked once the remote system responds with the state 
      of the pin. 
   */
   usaSheeld.setOnSubscribeOrDigitalChange(&toggleLed);
   /* Set an Led to pin 13. */ 
   pinMode(ledPin,OUTPUT);
   
 }
 
 void loop()
 {
   /* Say any sentences to be said out loud there in the USA smartphone. */
   if(VoiceRecognition.isNewCommandReceived())
  {
    /* Send the Command to the USA 1Sheeld system. */
    usaSheeld.sendMessage("USA",VoiceRecognition.getLastCommand());  
  }
  
 }
 
 /* Function to Toggle the LED according to the state comming from the remote 1Sheeld 
    system.
 */
 void toggleLed(byte pinNumber , bool remotePinValue)
 {
    /* Turn on the LED. */
    digitalWrite(ledPin,remotePinValue); 
 }

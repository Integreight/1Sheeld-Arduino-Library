/*

Text-To-Speech Shield Example

This example shows an application on 1Sheeld's text-to-speech shield.

By using this example, you can interact with your Arduino using voice commands.

*/

/* Include 1Sheeld library. */
#include <OneSheeld.h>

/* A command which will be compared. */
const char firstCommand[]="good morning one shield";

/* A command which will be compared. */
const char secondCommand[]="how is the weather today";

/* A command which will be compared. */
const char thirdCommand[]="turn on";

/* A name for the LED on pin 13. */
int ledPin = 13;

void setup()
{
  /* Start communication. */
  OneSheeld.begin();
  /* Set the LED pin as output. */
  pinMode(ledPin,OUTPUT);
}

void loop()
{
   /* Always check if a new voice command received. */ 
   if(VoiceRecognition.isNewCommandReceived())
   {
     /* Check if the voice command is the desired one. */
     if(!strcmp(firstCommand,VoiceRecognition.getLastCommand()))
     {
       /* 1Sheeld responds using text-to-speech. */
       TextToSpeech.say("Good morning sir");
     }
     /* Check if the voice command is the desired one. */
     else if(!strcmp(secondCommand,VoiceRecognition.getLastCommand()))
     {
       /* 1Sheeld responds using text-to-speech. */
       TextToSpeech.say("the weather is pretty good sir");
     }
     /* Check if the voice command is the desired one. */
     else if(!strcmp(thirdCommand,VoiceRecognition.getLastCommand()))
     {
       digitalWrite(ledPin,HIGH);
       /* 1Sheeld responds using text-to-speech. */
       TextToSpeech.say("led turned on");
     }
     else
     {
       digitalWrite(ledPin,LOW);
     }
   }
}

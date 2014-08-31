/*

Text-To-Speech Shield Example

This example shows an application on 1Sheeld's Text-To-Speech shield.

By using this example, you can interact with 1Sheeld using voice commands.

*/

/* Include 1Sheeld library. */
#include <OneSheeld.h>

/* A constant text which will be compared*/
const char *text1="good morning one shield";
/* A constant text which will be compared*/
const char *text2="how is the weather today";

void setup()
{
  /* Start communication*/
  OneSheeld.begin();
}

void loop ()
{
   /* Always check if a new voice command received */ 
   if(VoiceRecognition.isNewCommandReceived())
   {
     /* Compare voice commands with const text */
     if(!strcmp(text1,VoiceRecognition.getLastCommand()))
     {
       /* 1Sheeld respnods using text to speech */
       TextToSpeech.say("Good morning sir");
     }
     /* Compare voice commands with const text */
     else if(!strcmp(text2,VoiceRecognition.getLastCommand()))
     {
       /* 1Sheeld respnods using text to speech */
       TextToSpeech.say("the weather is pretty good sir");
     }
   }
}

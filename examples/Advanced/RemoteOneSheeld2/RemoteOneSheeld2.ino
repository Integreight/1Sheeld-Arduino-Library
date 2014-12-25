/*
 
RemoteOneSheeld Example #2

This example shows an application on remote 1Sheeld's feature.

By uploading this example on the 1Sheeld's system you can receive voice commands from 
another 1Sheeld system and say it loudly by the text to speech shield in 1Sheeld app.

Note : you have to burn RemoteOneSheeld1 on the other 1Sheeld for this example to work.

*/

/* Include 1Sheeld Library. */
#include <OneSheeld.h>

void setup()
{
  /* Start communication. */
  OneSheeld.begin();
  /* Set a certain function to be invoked once the remote system get a certain command. */
  OneSheeld.setOnNewMessage(&sayItLoud);
}

void loop()
{}

/* Function to say the command out loud using the TextToSpeech shield. */
void sayItLoud(char * remoteAddress ,char * key , char * voiceCommand)
{
  if(!strcmp(key,"USA"))
  {
   TextToSpeech.say(voiceCommand);
  }
}



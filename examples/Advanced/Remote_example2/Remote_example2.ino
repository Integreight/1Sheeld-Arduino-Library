/*
 
 RemoteOneSheeld Example #2
 
 This example shows an application on 1Sheel's Remote Feature.
 
 By burning this example on the the 1Sheels system you can receive the voice command from 
 the remote 1Sheeld system and say it loudly by the TextToSpeech shield in 1Sheeld app.
 
 Note : you have to burn Remote_example1 on the remote system1 to complete this example.
*/

/* Include 1Sheeld Library. */
#include <OneSheeld.h>


void setup()
{
  /* Start communication. */
  OneSheeld.begin();
  /* Set a certain function to be invoked once the remote system get a certain command. */
  OneSheeld.setOnStringMessage(&sayItLoud);
}

void loop()
{}

/* Function to say the command out loud using the TextToSpeech shield. */
void sayItLoud(String remoteAddress ,String key , String voiceCommand)
{
  TextToSpeech.say(voiceCommand);
}



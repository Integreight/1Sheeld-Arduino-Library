/*

Voice Recognition Shield Example

This example shows an application on 1Sheeld's voice recognition shield.

By using this example, you can play, pause and stop your smartphone's 
music using voice commands.

*/

/* Include 1Sheeld library. */
#include <OneSheeld.h>

/* Voice commands set by the user. */
const char playCommand[] = "play";
const char pauseCommand[] = "pause";
const char stopCommand[] = "stop";
const char nextCommand[] = "next";

void setup()
{
  /* Start Communication. */
  OneSheeld.begin();
  /* Error Commands handiling. */
  VoiceRecognition.setOnError(error);
  
  VoiceRecognition.start();
}

void loop () 
{
  /* Check if new command received. */
  if(VoiceRecognition.isNewCommandReceived())
  {
    /* Compare the play command. */
    if(!strcmp(playCommand,VoiceRecognition.getLastCommand()))
    {
      /* Play the track. */
      MusicPlayer.play();
    }
    /* Compare the pause command. */
    else if (!strcmp(pauseCommand,VoiceRecognition.getLastCommand()))
    {
      /* Pause the track. */
      MusicPlayer.pause();
    }
    /* Compare the stop command. */
    else if (!strcmp(stopCommand,VoiceRecognition.getLastCommand()))
    {
      /* Stop the track. */
      MusicPlayer.stop();
    }
    /* Compare the next command. */
    else if (!strcmp(nextCommand,VoiceRecognition.getLastCommand()))
    {
      /* Next track. */
      MusicPlayer.next();
    }
  }
}

/* Error checking function. */
void error(byte errorData)
{
  /* Switch on error and print it on the terminal. */
  switch(errorData)
  {
    case NETWORK_TIMEOUT_ERROR: Terminal.println("Network timeout");break;
    case NETWORK_ERROR: Terminal.println("Network Error");break;
    case AUDIO_ERROR: Terminal.println("Audio error");break;
    case SERVER_ERROR: Terminal.println("No Server");break;
    case SPEECH_TIMEOUT_ERROR: Terminal.println("Speech timeout");break;
    case NO_MATCH_ERROR: Terminal.println("No match");break;
    case RECOGNIZER_BUSY_ERROR: Terminal.println("Busy");break;
  }
}
